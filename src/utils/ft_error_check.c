/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:54:49 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/04 13:51:48 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void    ft_error (char *message)
{
    ft_printf("%s%s%s\n", RED, message, RESET_COLOR);
    exit (EXIT_FAILURE);
}

int	ft_s_numeric(char *s)
{
	if (*s && (*s == '-' || *s == '+'))
		s++;
	while (*s && ft_isdigit(*s))
		s++;
	return (*s != '\0');
}

int has_dup (t_stack *stack_a, int n)
{
    // while (stack_a && stack_a->n != n)
    //     stack_a = stack_a->next;
    if (stack_a && stack_a->n && n)
        ft_printf ("hey dup\n");
    //     ft_printf("has_dup: %s\n", stack_a->n);
    // if (stack_a  && stack_a != NULL)
    //     return (1);
    return (0);
}

int not_int_range(long n)
{
    return (n < INT_MIN || n > INT_MAX);
}