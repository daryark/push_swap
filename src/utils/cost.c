/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:53:46 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/13 23:34:25 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_abs(int	n)
{
	if (n < 0)
		return (-n);
	return n;
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
		ft_printf("cost: %d, num: %d, mid: %d\n", stack->i, stack->n, mid);
		mid--;
		cost++;
		stack = stack->next;
	}
}

t_stack	*final_cost(t_stack *stack_b)
{
	t_stack	*cheapest_node;
	int		amnt;

	cheapest_node = NULL;
	amnt = MAX_INT;
	while (stack_b)
	{
		if (amnt > (ft_abs(stack_b->n) + ft_abs(stack_b->target->n)))
		{
			amnt = ft_abs(stack_b->n) + ft_abs(stack_b->target->n);
			cheapest_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (cheapest_node);
}
