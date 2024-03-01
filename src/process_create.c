/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:10:00 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/01 22:47:37 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ft_process (char **av)
{
    int     i;
    long    n;
    t_stack *stack_a;
    // t_stack *stack_b;
    
    i = -1;
    stack_a = NULL;
    // stack_b = NULL;
    while (av[++i])
    {
        if (ft_s_numeric(av[i]))
            ft_error("Error");
        n = ft_atoi(av[i]);
        if (has_duplicate(stack_a, n) || not_int_range(n))
            ft_error("Error dup");
        // ft_printf("n: %d\n", n);
        ft_stack_addback(&stack_a, ft_stacknew(n));
    }
}