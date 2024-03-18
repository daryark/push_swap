/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:44:47 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/18 18:46:26 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_new_node_back(t_stack **stack, int n)
{
	t_stack		*node;

	node = ft_stacknew(n);
	if (!node)
	{
		ft_stackclean(stack);
		return ;
	}
	ft_stack_addback(stack, node);
	if (!stack)
		return ;
}

t_stack	*ft_stacknew(int n)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->n = n;
	node->i = 0;
	node->next = NULL;
	return (node);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stack_addback(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
		*stack = new;
	else
	{
		last = ft_stacklast(*stack);
		last->next = new;
	}
}

void	ft_stackclean(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
