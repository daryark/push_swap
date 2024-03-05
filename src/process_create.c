/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:10:00 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/05 16:32:45 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void    ft_process (char **av)
{
    int     i;
    long    n;
    t_stack *stack_a;
    t_stack *node;
    
    stack_a = NULL;
    node = NULL;
    n = 0;
    i = -1;
    while (av[++i])
    {
        if (ft_s_numeric(av[i]))
            ft_error("Error");
        n = ft_atol(av[i]);
        if (has_dup(stack_a, n) || not_int_range(n))
            ft_error("Error dup");
        node = ft_stacknew(n);
        if (!node)
        {
            ft_stackclear(&stack_a);
            return ;
        }
        ft_stack_addback(&stack_a, node);
    }
    ft_sort(&stack_a);
    ft_stackclear(&stack_a);
}
