/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:04:52 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/11 13:14:21 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
	int		diff;
	t_stack	*curr_node;

	head = stack;
	max = find_max(stack);
	reset_idx(stack);
	max->i = 0;
	while (stack_len--)
	{
		diff = INT_MAX;
		while (stack)
		{
			if ((max->n - stack->n) < diff && stack->i == -1)
			{
				diff = (max->n - stack->n);
				curr_node = stack;
			}
			stack = stack->next;
		}
		stack = head;
		curr_node->i = (ft_stacklen(stack) - stack_len);
		max = curr_node;
		ft_printf("stack_len %d\n", stack_len);
	}
}
