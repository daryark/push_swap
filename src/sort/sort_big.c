/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:24:16 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/20 15:53:19 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	quick_sort(t_stack **stack_a, t_stack **stack_b)
{
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
		do_dbl_rot_amnt(move_both, cheapest, stack_a, stack_b);
	do_rot_b_amnt(cheapest, stack_b);
	do_rot_a_amnt(cheapest->target, stack_a);
	pa(stack_a, stack_b);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	quick_sort(stack_a, stack_b);
	if (ft_stacklen(*stack_a) == 3)
		sort3(stack_a);
	while (ft_stacklen(*stack_b) > 0)
		turk_sort(stack_a, stack_b);
	if (!is_sorted(*stack_a))
	{
		set_cost(*stack_a);
		do_rot_a_amnt(find_min_node(*stack_a), stack_a);
	}
}
