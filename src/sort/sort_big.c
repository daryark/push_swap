/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:24:16 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/14 21:50:59 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	quick_sort(int stack_len, t_stack **stack_a, t_stack **stack_b)
{
	int	mid;

	mid = stack_len / 2;
	while (stack_len > 3)
	{
		ft_printf("----------------------\nstacklen: %d\n", stack_len);
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
			ft_printf("mid: %d\n", mid);
		}
	}
}

void	do_dbl_rot_amnt(int amnt, t_stack *cheapest, t_stack **a, t_stack **b)
{
	while (amnt--)
	{
		if (cheapest->i < 0 || cheapest->target->i < 0) 
			rrr(a, b);
		else
			rr(a, b);
	}
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*cheapest;
	int		move_both;

	head_a = *stack_a;
	head_b = *stack_b;
	cheapest = NULL;
	ft_printf("TURK SORT\n--------------------\n");
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
	ft_printf("\n--------------------\n");
	set_target_node(*stack_a, *stack_b);
	ft_printf("\n COST STACK A\n");
	set_cost(*stack_a);
	ft_printf("\n COST STACK B\n");
	set_cost(*stack_b);
	cheapest = final_cost(*stack_b);
	move_both = position_both(cheapest);
	ft_printf("move_both: %d\n", move_both);
	if (move_both)
	{
		if ((move_both < 0 && (cheapest->i < cheapest->target->i))
			|| (move_both > 0 && (cheapest->i > cheapest->target->i)))
		{
			move_both = ft_abs(cheapest->target->i);
			cheapest->i -= cheapest->target->i;
		}
		else
		{
			move_both = cheapest->i;
			cheapest->target->i -= cheapest->i;
		}
		do_dbl_rot_amnt(move_both, cheapest, stack_a, stack_b);
		ft_printf("STACK A\n");
	head_a = *stack_a;
	head_b = *stack_b;
	while (head_a)
	{
		ft_printf("%d,", (head_a)->n);
		head_a = (head_a)->next;
	}
	ft_printf("\n---------------\nSTACK B\n");
	while (head_b)
	{
		ft_printf("%d,", (head_b)->n);
		head_b = (head_b)->next;
	}
	}
	//fix this hardcode, and see if it actually works!!
	while (cheapest->i-- > 0)
		rb(stack_b);
	while (cheapest->target->i-- > 0)
		ra(stack_a);
	while (cheapest->i-- < 0)
		rrb(stack_b);
	while (cheapest->target->i-- < 0)
		rra(stack_a);
	//if i can rr or rrr both stacks, then do this
	//afther, minus the cost (i),
	//move the leftover moves for one of the stacks
	//pa
	//--------------------redo the sort while there is smth in stack_b
}
	// ft_printf("cheapest node: %d, target: %d\n",
	// cheapest_node->n, cheapest_node->target->n);

void	refresh_data(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
	ft_printf("refresh data\n");
}

void	sort_big(int stack_len, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max;

	max = find_max(*stack_a);
	quick_sort(stack_len, stack_a, stack_b);
	sort3(stack_a);
	turk_sort(stack_a, stack_b);
	refresh_data(stack_a, stack_b);
}
