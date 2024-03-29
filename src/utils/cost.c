/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:53:46 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/18 17:10:08 by dyarkovs         ###   ########.fr       */
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

int	max_move(t_stack *stack_b)
{
	if (stack_b->i < 0)
	{
		if (stack_b->i < stack_b->target->i)
			return (ft_abs(stack_b->i));
		else
			return (ft_abs(stack_b->target->i));
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
	int		move_both;

	amnt = INT_MAX;
	while (stack_b)
	{
		move_both = position_both(stack_b);
		if (move_both && max_move(stack_b) < amnt)
		{
			if ((move_both < 0 && (stack_b->i < stack_b->target->i))
				|| (move_both > 0 && (stack_b->i > stack_b->target->i)))
				amnt = ft_abs(stack_b->i);
			else
				amnt = ft_abs(stack_b->target->i);
			cheapest_node = stack_b;
		}
		else if ((ft_abs(stack_b->i) + ft_abs(stack_b->target->i)) < amnt)
		{
			amnt = ft_abs(stack_b->i) + ft_abs(stack_b->target->i);
			cheapest_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (cheapest_node);
}

// int	is_cheaper(int move_both, int *amnt, t_stack *stack_b)
// {
// 	if (move_both && max_move(stack_b) < *amnt)
// 	{
// 		if ((move_both < 0 && (stack_b->i < stack_b->target->i))
// 			|| (move_both > 0 && (stack_b->i > stack_b->target->i)))
// 			amnt = ft_abs(stack_b->i);
// 		else
// 			amnt = ft_abs(stack_b->target->i);
// 	}
// }

// t_stack	*final_cost(t_stack *stack_b)
// {
// 	t_stack	*cheapest_node;
// 	int		amnt;
// 	int		move_both;

// 	cheapest_node = NULL;
// 	amnt = INT_MAX;
// 	while (stack_b)
// 	{
// 		move_both = position_both(stack_b);
// 		if (is_dbl_cheaper(max_move(stack_b), &amnt, stack_b))
// 			cheapest_node = stack_b;
// 		else if (amnt > (ft_abs(stack_b->i) + ft_abs(stack_b->target->i)))
// 		{
// 			amnt = ft_abs(stack_b->i) + ft_abs(stack_b->target->i);
// 			cheapest_node = stack_b;
// 		}
// 		stack_b = stack_b->next;
// 	}
// 	return (cheapest_node);
// }
