/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:10:00 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/06 13:49:51 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	ft_process(char **av)
{
	int		i;
	long	n;
	t_stack	*stack_a;

	stack_a = NULL;
	i = -1;
	while (av[++i])
	{
		if (ft_s_numeric(av[i]))
			ft_error("Error");
		n = ft_atol(av[i]);
		if (has_dup(stack_a, n) || not_int_range(n))
			ft_error("Error dup");
		ft_stack_addback(&stack_a, ft_stacknew(n));
		if (!stack_a)
			return ;
	}
	ft_sort(&stack_a);
	ft_stackclear(&stack_a);
}
