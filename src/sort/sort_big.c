/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:24:16 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/15 19:40:19 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	quick_sort(int stack_len, t_stack **stack_a, t_stack **stack_b)
{
	int	mid;

	mid = stack_len / 2;
	while (stack_len > 3)
	{
		// ft_printf("----------------------\nstacklen: %d\n", stack_len);
		if (stack_len > mid)
		{
			if ((*stack_a)->i <= mid)
			{
				pb(stack_a, stack_b);
				stack_len--;
			}
			else
				ra(stack_a);
		}
		else
		{
			mid /= 2;
			set_idx(stack_len, *stack_a);
			// ft_printf("mid: %d\n", mid);
		}
	}
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
		// ft_printf("%sA: %d, B: %d%s\n",YELLOW, (*a)->n, (*b)->n, RESET_COLOR);
	}
	// ft_printf("%si:%d, t:%d%s\n", MAGENTA, cheapest->i, cheapest->target->i, RESET_COLOR);
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

	// head_a = *stack_a;
	// head_b = *stack_b;
	cheapest = NULL;
	// ft_printf("TURK SORT\n--------------------\n");
	// ft_printf("STACK A\n");
	// while (head_a)
	// {
	// 	ft_printf("%d,", (head_a)->n);
	// 	head_a = (head_a)->next;
	// }
	// ft_printf("\n---------------\nSTACK B\n");
	// while (head_b)
	// {
	// 	ft_printf("%d,", (head_b)->n);
	// 	head_b = (head_b)->next;

	// }
	// ft_printf("\n--------------------\n");
	set_target_node(*stack_a, *stack_b);
	// ft_printf("\n COST STACK A\n");
	set_cost(*stack_a);
	// ft_printf("\n COST STACK B\n");
	set_cost(*stack_b);
	cheapest = final_cost(*stack_b);
	move_both = position_both(cheapest);
	// ft_printf("move_both: %d\n", move_both);
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
	//*do one func, but pass cheapest first, next call - pass cheapest->target
	//!use this same func to rot stack_a until finish at the end
	do_rot_amnt(cheapest, stack_a, stack_b);
	pa(stack_a, stack_b);
	// ft_printf("STACK A\n");
	// head_a = *stack_a;
	// head_b = *stack_b;
	// while (head_a)
	// {
	// 	ft_printf("%d,", (head_a)->n);
	// 	head_a = (head_a)->next;
	// }
	// ft_printf("\n---------------\nSTACK B\n");
	// while (head_b)
	// {
	// 	ft_printf("%d,", (head_b)->n);
	// 	head_b = (head_b)->next;
	// }
	//if i can rr or rrr both stacks, then do this
	//afther, minus the cost (i),
	//move the leftover moves for one of the stacks
	//pa
	//--------------------redo the sort while there is smth in stack_b
}
	// ft_printf("cheapest node: %d, target: %d\n",
	// cheapest_node->n, cheapest_node->target->n);

// void	refresh_data(t_stack **stack_a, t_stack **stack_b)
// {
// 	*stack_a = NULL;
// 	*stack_b = NULL;
// 	ft_printf("refresh data\n");
// }

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	// int	max_idx;
	// t_stack	*head_a;
	// t_stack	*head_b;

	quick_sort(ft_stacklen(*stack_a), stack_a, stack_b);
	sort3(stack_a);
	while (ft_stacklen(*stack_b) > 0)
		turk_sort(stack_a, stack_b);
	// ft_printf("%sAFTER TURK%s\n", YELLOW, RESET_COLOR);
	// if the n value is after mid => ra, else => rra while is not sorted
	if (!is_sorted(*stack_a))
	{
		// set_cost(*stack_a);
		// max_idx = find_max(*stack_a)->i;
		// if (max_idx >)
		// {
		// 	/* code */
		// }
		set_cost(*stack_a);
		// head_a = *stack_a;
		// head_b = *stack_b;
		// ft_printf("STACK A\n");
		// while (head_a)
		// {
		// 	ft_printf("%d(p %d), ", (head_a)->n, (head_a)->i);
		// 	head_a = (head_a)->next;
		// }
		// ft_printf("\n---------------\nSTACK B\n");
		// while (head_b)
		// {
		// 	ft_printf("%d,", (head_b)->n);
		// 	head_b = (head_b)->next;
		// }
		do_rot_amnt(find_max(*stack_a)->next, stack_a, stack_b);

		// ra(stack_a);
	}
	// while (*stack_a)
	// {
	// 	ft_printf("%d,", (*stack_a)->n);
	// 	*stack_a = (*stack_a)->next;
	// }
	// refresh_data(stack_a, stack_b);
}
