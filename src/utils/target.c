/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:50:36 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/13 15:55:59 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reset_target_node(t_stack *stack_b)
{
	while (stack_b)
	{
		stack_b->target = NULL; //what to set as default here? do i even need to reset them to default?
		stack_b = stack_b->next;
	}
}

void	set_target_node(t_stack *stack_a, t_stack *stack_b)
{
	//Do i need to reset to default targets? or use the prev ones for comparison on next rounds?
	t_stack	*head_a;
	int		diff;

	while (stack_b)
	{
		diff = stack_a->n - stack_b->n; //first (a->n - b->n) = diff
		stack_b->target = stack_a; //first a->n = target
		head_a = stack_a; //move a to next
		while (head_a)
		{
			if ((diff < 0 && (head_a->n - stack_b->n) < diff)
				|| ((head_a->n - stack_b->n) > 0 
				&& (diff - (head_a->n - stack_b->n)) > 0))
			{
				diff = (head_a->n - stack_b->n);
				stack_b->target = head_a;
			}
			head_a = head_a->next;
		}
		ft_printf("b: %d, target a: %d\n", stack_b->n, stack_b->target->n);
		stack_b = stack_b->next;
	}
}
