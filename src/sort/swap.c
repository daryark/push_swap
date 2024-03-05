/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:49:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/05 17:03:15 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int swap (t_stack **stack)
{
    int tmp;

    if ((*stack) == NULL || (*stack)->next == NULL)
        return (0);
    tmp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = tmp;
    return (1);
}

void    sa(t_stack **stack_a)
{
    if(swap(stack_a))
        ft_printf ("sa\n");
}

void    sb(t_stack **stack_b)
{
    if(swap(stack_b))
        ft_printf ("sb\n");
}

void    ss(t_stack **stack_a, t_stack **stack_b)
{
    if(swap(stack_a) || swap(stack_b))
        ft_printf ("ss\n");
}

