/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:44:47 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/06 13:57:19 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*ft_stacknew(int n)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->n = n;
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

void	ft_del_stacknode(t_stack *node)
{
	if (!node)
		return ;
	// node->n = 0;
	// node->next = NULL;
	free(node);
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		ft_printf ("clear stack | ");
		tmp = (*stack)->next;
		free(*stack);
		// ft_del_stacknode(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	ft_stacklen(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	ft_printf("len: %d\n", len);
	return (len);
}
