/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:21:01 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/03 19:42:17 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../push_swap.h"

int rev_rotate (t_stack **stack)
{
    t_stack *append;

    append = *stack;
    ft_stacklast((*stack)->next)->next = append;
    append->next = NULL; //head moved
    
}

void    rra(t_stack **stack_a)
{
    if(rev_rotate(stack_a))
        ft_printf ("ra\n");
}

void    rrb(t_stack **stack_b)
{
    if(rev_rotate(stack_b))
        ft_printf ("rb\n");
}

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    if(rev_rotate(stack_a) || rev_rotate (stack_b))
        ft_printf ("rr\n");
}