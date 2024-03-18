/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:48:20 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/18 17:48:50 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_stacklen(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack	*find_max_node(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->n > max->n)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->n < min->n)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
