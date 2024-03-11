/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:04:52 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/11 12:24:51 by dyarkovs         ###   ########.fr       */
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

void	set_idx(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		ft_printf("idx %d\n", i);
		stack = stack->next;
		i++;
	}
}
