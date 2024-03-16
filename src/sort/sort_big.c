/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:24:16 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/16 20:38:05 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("n: %d	i: %d\n", stack->n, stack->i);
		stack= stack->next;
	}
}

void	quick_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		pivot;

	set_idx(ft_stacklen(*stack_a), *stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (ft_stacklen(*stack_a) <= 3)
	{
		if (!is_sorted(*stack_a))
			sort3(stack_a);
		return ;
	}
	pivot = ft_stacklen(*stack_a) / 2;
	while (ft_stacklen(*stack_a) != pivot && ft_stacklen(*stack_a) > 3
	&& !is_sorted(*stack_a))
	{
		if ((*stack_a)->i <= pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	return (quick_sort(stack_a, stack_b));
	// int	mid;
	// int	stack_len;

	// stack_len = ft_stacklen(*stack_a);
	// stack_len--;
	// mid = stack_len / 2;
	// print_stack(*stack_a);
	// while (stack_len > 3)
	// {
	// 	// ft_printf("----------------------\nstacklen: %d\n", stack_len);
	// 	if (stack_len > mid)
	// 	{
	// 		if ((*stack_a)->i <= mid)
	// 		{
	// 			ft_printf("PB n: %d, i: %d |	^%d\n", (*stack_a)->n, (*stack_a)->i, mid);
	// 			pb(stack_a, stack_b);
	// 			stack_len--;
	// 		}
	// 		else
	// 		{
	// 			ft_printf("%sRA n: %d, i: %d |	^%d%s\n", GREEN, (*stack_a)->n, (*stack_a)->i, mid, RESET_COLOR);
	// 			ra(stack_a);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		mid /= 2;
	// 		set_idx(stack_len, *stack_a);
	// 		// ft_printf("mid: %d\n", mid);
	// 	}
	// }
}

void	do_dbl_rot_amnt(int amnt, t_stack *cheapest, t_stack **a, t_stack **b)
{
	// ft_printf("%si:%d, t:%d%s\n", MAGENTA, cheapest->i, cheapest->target->i, RESET_COLOR);
	if (amnt > 0)
	{
		while (cheapest->i && cheapest->target->i)
		{
			cheapest->i--;
			cheapest->target->i--;
			rr(a, b);
		}
	}
	else if (amnt < 0)
	{
		// ft_printf("%sA: %d, B: %d%s\n",YELLOW, (*a)->n, (*b)->n, RESET_COLOR);
		while (cheapest->i && cheapest->target->i)
		{
			cheapest->i++;
			cheapest->target->i++;
			rrr(a, b);
		}
	}
}

void	do_rot_amnt(t_stack *node, t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b)
	{
		if (node->i > 0)
		{
			while (node->i-- > 0)
				rb(stack_b);
		}
		else if (node->i < 0)
		{
			while (node->i++ < 0)
				rrb(stack_b);
		}
		node = node->target;
	}
	if (node->i > 0)
	{
		while (node->i-- > 0)
			ra(stack_a);
	}
	else if (node->i < 0)
	{
		while (node->i++ < 0)
			rra(stack_a);
	}
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;
	int		move_both;

	cheapest = NULL;
	set_target_node(*stack_a, *stack_b);
	set_cost(*stack_a);
	set_cost(*stack_b);
	cheapest = final_cost(*stack_b);
	move_both = position_both(cheapest);
	if (move_both)
	{
		// if ((move_both < 0 && (cheapest->i < cheapest->target->i))
		// 	|| (move_both > 0 && (cheapest->i > cheapest->target->i)))
		// {
		// 	move_both = ft_abs(cheapest->target->i);
		// 	cheapest->i -= cheapest->target->i;
		// 	ft_printf("i: %d, target: %d. -=t\n", cheapest->i, cheapest->target->i);
		// }
		// else
		// {
		// 	move_both = cheapest->i;
		// 	cheapest->target->i -= cheapest->i;
		// 	ft_printf("i: %d, target: %d. -=i\n", cheapest->i, cheapest->target->i);
		// }
		do_dbl_rot_amnt(move_both, cheapest, stack_a, stack_b);
	}
	do_rot_amnt(cheapest, stack_a, stack_b);
	pa(stack_a, stack_b);
	//if i can rr or rrr both stacks, then do this
	//afther, minus the cost (i),
	//move the leftover moves for one of the stacks
	//pa
	//--------------------redo the sort while there is smth in stack_b
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	quick_sort(stack_a, stack_b);
	while (ft_stacklen(*stack_b) > 0)
		turk_sort(stack_a, stack_b);
	if (!is_sorted(*stack_a))
	{
		// set_cost(*stack_a);
		// max_idx = find_max(*stack_a)->i;
		// if (max_idx >)
		// {
		// 	/* code */
		// }
		set_cost(*stack_a);
		do_rot_amnt(find_max(*stack_a)->next, stack_a, stack_b);
	}
}
