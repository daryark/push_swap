/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:35:06 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/06 16:15:43 by dyarkovs         ###   ########.fr       */
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


int	main(int ac, char **av)
{
	if (ac < 2 || (ac == 2 && av[1][0]))
		return (0);
	av++;
	if (ac == 2)
		av = ft_split(*av, ' ');
	ft_process(av);

	return (0);
}
