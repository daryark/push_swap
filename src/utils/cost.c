/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:53:46 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/14 20:26:20 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

//return -1 if both below middle,
//		  1 if both above middle,
//		  0 if none of cases.
int	position_both(t_stack *node_b)
{
	int	res;

	if (node_b->i > 0 && node_b->target->i > 0)
		res = 1;
	else if (node_b->i < 0 && node_b->target->i < 0)
		res = -1;
	else
		res = 0;
	ft_printf("cheapest pos: %d, target pos: %d, both: %d\n", node_b->i, node_b->target->i, res);
	return (res);
	//--------------------------------------------
	// int	both_above;
	// int	both_below;

	// both_above = (node_b->i > 0 && node_b->target->i > 0);
	// both_below = (node_b->i < 0 && node_b->target->i < 0);
	// if (move_both != 0)
	// {
	// 	if ((move_both < 0 && (node_b->i < node_b->target->i))
	// 		|| (move_both > 0 && (node_b->i > node_b->target->i)))
	// 		return (node_b->i);
	// 	else
	// 		return (node_b->target->i);
	// }
	// return (0);
	//--------------------------------------------
	// if (node_b->i < 0 && node_b->target->i < 0)
	// {
	// 	if (node_b->i < node_b->target->i)
	// 		return (node_b->i);
	// 	else
	// 		return (node_b->target->i);
	// }
	// else if (node_b->i > 0 && node_b->target->i > 0)
	// {
	// 	if (node_b->i < node_b->target->i)
	// 		return (node_b->target->i);
	// 	else
	// 		return (node_b->i);
	// }
	// return (0);
}

void	set_cost(t_stack *stack)
{
	int	mid;
	int	stack_len;
	int	cost;

	stack_len = ft_stacklen(stack);
	mid = stack_len / 2 + 1;
	cost = 0;
	ft_printf("stack_len: %d\n", stack_len);
	while (stack)
	{
		if (!mid && stack_len % 2 == 1)
			cost = (cost - 1) * -1;
		else if (!mid && stack_len % 2 == 0)
			cost = (cost - 2) * -1;
		stack->i = cost;
		ft_printf("n: %d, cost: %d, 	|			mid: %d\n", stack->n, stack->i, mid);
		mid--;
		cost++;
		stack = stack->next;
	}
}

t_stack	*final_cost(t_stack *stack_b)
{
	t_stack	*cheapest_node;
	int		amnt;
	int		move_both;

	cheapest_node = NULL;
	amnt = INT_MAX;
	ft_printf("\n----------------\n");
	while (stack_b)
	{
		move_both = position_both(stack_b);
		if (move_both && amnt > move_both)
		{
			if ((move_both < 0 && (stack_b->i < stack_b->target->i))
				|| (move_both > 0 && (stack_b->i > stack_b->target->i)))
				amnt = stack_b->i;
			else
				amnt = stack_b->target->i;
			cheapest_node = stack_b;
		}
		else if (amnt > (ft_abs(stack_b->i) + ft_abs(stack_b->target->i)))
		{
			amnt = ft_abs(stack_b->i) + ft_abs(stack_b->target->i);
			cheapest_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	ft_printf("final smallest cost: %d, node_to_move: %d\n", amnt, cheapest_node->n);
	return (cheapest_node);
}
	//*check again if final cost and position_both works correct!!!