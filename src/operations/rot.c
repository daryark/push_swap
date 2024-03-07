/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:03:00 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/07 14:00:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int rotate (t_stack **stack)
{
    t_stack *append;

    if ((*stack) == NULL || (*stack)->next == NULL)
        return (0);
    append = *stack; //preserve head
    ft_stacklast((*stack)->next)->next = append; //find last el and connect prev_head after
    *stack = append->next; //reassign head to next elem
    append->next = NULL; //prev head is now the last and the new head saved, so next set to NULL
    return (1);
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