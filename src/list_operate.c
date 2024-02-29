/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:44:47 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/29 19:59:45 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *ft_stacknew (int n)
{
    t_stack node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->n = n;
    node->next = NULL;
    return (node);
}

t_stack *ft_stacklast(t_stack *stack)
{
    while (stack && stack->next)
        stack = stack->next;
    return (stack);
}

void    ft_stack_addback(t_stack **stack, t_stack *new)
{
    t_stack *node;

    if (!*stack)
        *stack = new;
    else
    {
        last = ft_stacklast(*stack);
        last->next = new;
    }
}