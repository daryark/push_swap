/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:50:36 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/18 17:49:59 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	reset_target_node(t_stack *stack)
{
	while (stack)
	{
		stack->target = NULL;
		stack = stack->next;
	}
}

void	set_target_node(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*head_a;
	int		diff;

	reset_target_node(stack_a);
	reset_target_node(stack_b);
	while (stack_b)
	{
		diff = stack_a->n - stack_b->n;
		stack_b->target = stack_a;
		head_a = stack_a->next;
		while (head_a)
		{
			if ((diff < 0 && (head_a->n - stack_b->n) < diff)
				|| (diff < 0 && (head_a->n - stack_b->n) > 0)
				|| (diff > 0 && (diff - (head_a->n - stack_b->n)) > 0
					&& (diff - (head_a->n - stack_b->n)) < diff))
			{
				diff = (head_a->n - stack_b->n);
				stack_b->target = head_a;
			}
			head_a = head_a->next;
		}
		stack_b = stack_b->next;
	}
}
