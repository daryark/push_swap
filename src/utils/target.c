/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:50:36 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/12 21:09:28 by dyarkovs         ###   ########.fr       */
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
	//do i need to reset to default targets? or use the prev ones for comparison on next rounds?
	t_stack	*head_a;
	int		diff;

	while (stack_b)
	{
		head_a = stack_a;
		diff = head_a->n - stack_b->n;
		stack_b->target = stack_a;
		while (head_a)
		{
			//if difference is below zero, preserve the smallest minus num;
			//if diff is above zero, preserve the smallest num above zero;
			head_a = head_a->next;
		}
		stack_b = stack_b->next;
	}
}
