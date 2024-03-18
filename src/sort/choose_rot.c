/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:25:36 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/18 17:33:58 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	do_dbl_rot_amnt(int amnt, t_stack *cheapest, t_stack **a, t_stack **b)
{
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
		while (cheapest->i && cheapest->target->i)
		{
			cheapest->i++;
			cheapest->target->i++;
			rrr(a, b);
		}
	}
}

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
