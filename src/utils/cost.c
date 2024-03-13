/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:53:46 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/13 22:49:46 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
