/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:50:36 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/14 17:16:46 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//if this funciton is actually used somewhere?? if no - use it when init stack and pb!
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
	t_stack	*head_a;
	int		diff;

	while (stack_b)
	{
		diff = stack_a->n - stack_b->n;
		stack_b->target = stack_a;
		head_a = stack_a->next;
		while (head_a)
		{
			if ((diff < 0 && (head_a->n - stack_b->n) < diff)
				|| (diff < 0 && (head_a->n - stack_b->n) > 0)
				|| (diff > 0 && (diff - (head_a->n - stack_b->n)) > 0))
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
