/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:09:41 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/15 15:15:01 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_del_stacknode(t_stack *node)
{
	if (!node)
		return ;
	// node->n = 0;
	// node->next = NULL;
	free(node);
}

void	ft_stackclean(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		// ft_printf ("clear stack | ");
		tmp = (*stack)->next;
		free(*stack);
		// ft_del_stacknode(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}