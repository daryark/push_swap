/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:04:52 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/18 18:02:00 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reset_idx(t_stack *stack)
{
	while (stack)
	{
		stack->i = 0;
		stack = stack->next;
	}
}

//chooses max from non set idxs,
//so the last max is the pre smallest - 1 idx, 0 idx leaves 0.
t_stack	*find_next_max(t_stack *stack)
{
	t_stack	*new_max_node;

	new_max_node = NULL;
	while (stack && stack->i != 0)
		stack = stack->next;
	if (stack)
		new_max_node = stack;
	while (stack)
	{
		if (new_max_node->n < stack->n && stack->i == 0)
			new_max_node = stack;
		stack = stack->next;
	}
	return (new_max_node);
}

void	set_idx(t_stack **stack)
{
	t_stack	*max_node;
	int		stack_len;

	stack_len = ft_stacklen(*stack);
	reset_idx(*stack);
	max_node = NULL;
	while (--stack_len)
	{
		max_node = find_next_max(*stack);
		max_node->i = stack_len;
	}
}
