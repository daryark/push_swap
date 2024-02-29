/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:10:00 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/29 20:01:11 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ft_process (char **av)
{
    int i;
    t_stack *stack_a;
    t_stack *stack_b;
    
    i = -1;
    stack_a = NULL;
    stack_b = NULL;
    while (av[++i])
        ft_stackadd_back(*stack_a, ft_stacknew(ft_atoi(av[i])));


}