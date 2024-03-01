/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:10:00 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/02 00:05:50 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ft_process (char **av)
{
    int     i;
    long    n;
    t_stack *stack_a;
    t_stack *node;
    
    i = -1;
    stack_a = NULL;
    node = NULL;
    while (av[++i])
    {
        if (ft_s_numeric(av[i]))
            ft_error("Error");
        n = ft_atoi(av[i]);
        if (has_duplicate(stack_a, n) || not_int_range(n))
            ft_error("Error dup");
        node = ft_stacknew(n);
        if (!node)
            return ;
        ft_stack_addback(&stack_a, node);
    }
}