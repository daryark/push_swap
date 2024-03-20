/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:35:06 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/20 15:50:50 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_process(char **av)
{
	int			i;
	long long	n;
	t_stack		*stack_a;

	stack_a = NULL;
	i = -1;
	while (av[++i])
	{
		if (ft_is_numeric(av[i]))
			ft_error("Error");
		n = ft_atol(av[i]);
		if (not_int_range(n) || has_dup(stack_a, n))
			ft_error("Error");
		ft_new_node_back(&stack_a, n);
		if (!stack_a)
			return ;
	}
	if (stack_a)
	{
		ft_sort(&stack_a);
		ft_stackclean(&stack_a);
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	av++;
	ft_process(av);
	return (0);
}
