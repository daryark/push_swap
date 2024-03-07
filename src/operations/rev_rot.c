/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:21:01 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/07 13:55:05 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../push_swap.h"

int rev_rotate(t_stack **stack)
{
    t_stack *head;
    t_stack *new_head;

    if ((*stack) == NULL || (*stack)->next == NULL)
        return (0);
    head = *stack; 
    while ((*stack)->next->next)
        *stack = (*stack)->next; //pre-last elem will be last, so it's next becomes NULL
    new_head = (*stack)->next; //last elem will be new head
    (*stack)->next = NULL; //actually reassign next to NULL after saving last node
    new_head->next = head; //link all the stack to new head
    *stack = new_head; //dereference the link to update the actual node it points to
    return (1);
}

void    rra(t_stack **stack_a)
{
    if(rev_rotate(stack_a))
        ft_printf ("rra\n");
}

void    rrb(t_stack **stack_b)
{
    if(rev_rotate(stack_b))
        ft_printf ("rrb\n");
}

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    if(rev_rotate(stack_a) || rev_rotate(stack_b))
        ft_printf ("rrr\n");
}
