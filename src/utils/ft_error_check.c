/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:54:49 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/18 18:45:33 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_error(char *message)
{
	ft_printf("%s", RED);
	write(2, message, 5);
	ft_printf("%s\n", RESET_COLOR);
	exit(EXIT_FAILURE);
}

int	ft_is_numeric(char *s)
{
	if (*s && (*s == '-' || *s == '+'))
		s++;
	while (*s && ft_isdigit(*s))
		s++;
	return (*s != '\0');
}

int	has_dup(t_stack *stack_a, long n)
{
	while (stack_a)
	{
		if (stack_a->n == n)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	not_int_range(long long n)
{
	return (n < INT_MIN || n > INT_MAX);
}
