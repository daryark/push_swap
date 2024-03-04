/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:29:13 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/03 20:44:40 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int ft_is_sorted(t_stack *stack_a)
{
    while (stack_a && stack_a->next)
    {
        if (stack_a->n > stack_a->next->n)
            return (0);
    }
    return (1);
}

void    ft_sort (t_stack **stack_a)
{
    //add stack_b here
    if (ft_is_sorted(*stack_a))
        return ;
    // else
    //     ft_sort_big(&stack_a);
        //maybe don't separate the functions that much, and do other check-sorts here
        //only inner operations of sorting do elsewhere.
}