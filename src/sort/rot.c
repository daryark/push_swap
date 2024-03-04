/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:03:00 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/03 19:42:36 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int rotate (t_stack **stack)
{
    t_stack *append;

    append = *stack;
    ft_stacklast((*stack)->next)->next = append;
    append->next = NULL; //head moved
    
}

void    ra(t_stack **stack_a)
{
    if(rotate(stack_a))
        ft_printf ("ra\n");
}

void    rb(t_stack **stack_b)
{
    if(rotate(stack_b))
        ft_printf ("rb\n");
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
    if(rotate(stack_a) || rotate (stack_b))
        ft_printf ("rr\n");
}