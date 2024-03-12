/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:04:52 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/12 18:28:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (max->n < stack->n)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	reset_idx(t_stack *stack)
{
	while (stack)
	{
		stack->i = -1;
		stack = stack->next;
	}
}

void	set_idx(int stack_len, t_stack *stack)
{
	t_stack	*head;
	t_stack	*max;
	t_stack	*curr_node;
	int		diff;

	max = find_max(stack);
	reset_idx(stack);
	while (stack_len--)
	{
		max->i = stack_len;
		diff = INT_MAX;
		head = stack;
		while (head)
		{
			if ((max->n - head->n) < diff && head->i == -1)
			{
				diff = (max->n - head->n);
				curr_node = head;
			}
			head = head->next;
		}
		max = curr_node;
	}
}

	// head = stack;
	// while (head)
	// {
	// 	ft_printf("%d, ", head->n);
	// 	head = head->next;
	// }
	// printf("\n");