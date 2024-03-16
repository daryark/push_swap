/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:53:46 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/15 20:02:47 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	position_both(t_stack *node_b)
{
	int	res;

	if (node_b->i > 0 && node_b->target->i > 0)
		res = 1;
	else if (node_b->i < 0 && node_b->target->i < 0)
		res = -1;
	else
		res = 0;
	return (res);
}

void	set_cost(t_stack *stack)
{
	int	mid;
	int	stack_len;
	int	cost;

	stack_len = ft_stacklen(stack);
	mid = stack_len / 2 + 1;
	cost = 0;
	while (stack)
	{
		if (!mid && stack_len % 2 == 1)
			cost = (cost - 1) * -1;
		else if (!mid && stack_len % 2 == 0)
			cost = (cost - 2) * -1;
		stack->i = cost;
		mid--;
		cost++;
		stack = stack->next;
	}
}

int		max_move(t_stack *stack_b)
{
	if (stack_b->i < 0)
	{
		if (stack_b->i < stack_b->target->i)
			return (ft_abs(stack_b->i));
		else
			return (stack_b->target->i);
	}
	else if (stack_b->i > 0)
	{
		if (stack_b->i > stack_b->target->i)
			return (stack_b->i);
		else
			return (stack_b->target->i);
	}
	return (0);
}

t_stack	*final_cost(t_stack *stack_b)
{
	t_stack	*cheapest_node;
	int		amnt;
	int		curr_amnt;

	cheapest_node = NULL;
	amnt = INT_MAX;
	while (stack_b)
	{
		curr_amnt = ft_abs(stack_b->i) + ft_abs(stack_b->target->i);
		 if (amnt > curr_amnt)
		{
			amnt = curr_amnt;
			cheapest_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (cheapest_node);
}