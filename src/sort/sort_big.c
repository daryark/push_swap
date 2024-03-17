/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:24:16 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/17 23:26:13 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("n: %d	i: %d\n", stack->n, stack->i);
		stack = stack->next;
	}
}

t_stack	*find_max_node(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->n > max->n)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->n < min->n)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	is_almost_sorted(t_stack *stack_a)
{
	t_stack *max_node;
	t_stack *min_node;

	max_node = find_max_node(stack_a);
	min_node = find_min_node(stack_a);
	while (stack_a && stack_a->next)
	{
		//not only these two nodes need to be max and min next, but all the other
		// nodes need to follow EXACTLY from lowest to next highest!
		if (!(stack_a->n < stack_a->next->n)
			&& !(stack_a->n == max_node->n && stack_a->next->n == min_node->n))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	quick_sort(t_stack **stack_a, t_stack **stack_b)
{
// 	// int		pivot;

	set_idx(stack_a);
	// print_stack(*stack_a);
	// print_stack(*stack_b);
	// if (ft_stacklen(*stack_a) <= 3 || is_sorted(*stack_a))
	// {
	// 	if (!is_sorted(*stack_a))
	// 		sort3(stack_a);
	// 	return  ;
	// }
	// pivot = ft_stacklen(*stack_a) / 2;
	// while (ft_stacklen(*stack_a) != pivot && ft_stacklen(*stack_a) > 3
	// 	&& !is_sorted(*stack_a))
	// {
	// 	if ((*stack_a)->i <= pivot)
			// pb(stack_a, stack_b);
	// 	else
	// 		ra(stack_a);
	// }
	// return (quick_sort(stack_a, stack_b));
	// int		pivot;
	
	// set_idx(stack_a);
	// print_stack(*stack_a);
	// ft_printf("--------B--------\n");
	// print_stack(*stack_b);
	// if (is_sorted(*stack_a))
	// 	return ;
	// if (ft_stacklen(*stack_a) <= 3)
	// {
	// 	if (!is_sorted(*stack_a))
	// 		sort3(stack_a);
	// 	return ;
	// }
	// pivot = ft_stacklen(*stack_a) / 2;
	// ft_printf("pivot: %d\n", pivot);
	// while (ft_stacklen(*stack_a) != pivot && ft_stacklen(*stack_a) > 3)
	// {
	// 	if ((*stack_a)->i <= pivot)
	// 	{
	// 		// ft_printf("PB n: %d, i: %d |	m:%d\n", (*stack_a)->n, (*stack_a)->i, pivot);
	// 		pb(stack_a, stack_b);
	// 	}
	// 	else
	// 	{
	// 		// ft_printf("RRA n: %d, i: %d |	m:%d\n", (*stack_a)->n, (*stack_a)->i, pivot);
	// 		ra(stack_a);
	// 	}
	// }
	// return (quick_sort(stack_a, stack_b));
	int	mid;
	int	stack_len;

	stack_len = ft_stacklen(*stack_a);
	mid = stack_len / 2;
	set_idx(stack_a);
	while (stack_len > 3 && !is_sorted(*stack_a))
	{
		if (stack_len <= mid)
		{
			set_idx(stack_a);
			mid /= 2;
		}
		else
		{
			if ((*stack_a)->i <= mid)
			{
				pb(stack_a, stack_b);
				stack_len--;
			}
			else
				ra(stack_a);
		}
		// if (is_almost_sorted(*stack_a))
		// 	{
		// 		do_rot_a_amnt(find_min_node(*stack_a), stack_a);
		// 		return ;
		// 	}
	}
	if (stack_len == 3)
		sort3(stack_a);
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

//node - the one that need to be first, so choose the side to rotate it faster
// stack_b can go with NULL (when already empty), so only A will be rotated then
void	do_rot_b_amnt(t_stack *node, t_stack **stack_b)
{
	if (!*stack_b)
		return ;

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
}

void	do_rot_a_amnt(t_stack *node, t_stack **stack_a)
{
	if (!*stack_a)
		return ;
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
	do_rot_b_amnt(cheapest, stack_b);
	do_rot_a_amnt(cheapest->target, stack_a);

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
	// 	// set_cost(*stack_a);
	// 	// max_idx = find_max(*stack_a)->i;
	// 	// if (max_idx >)
	// 	// {
	// 	// 	/* code */
	// 	// }
		set_cost(*stack_a);
		do_rot_a_amnt(find_min_node(*stack_a), stack_a);
	}
	//!temp, remove later these two lines below
	ft_stackclean(stack_a);
	ft_stackclean(stack_b);
}
