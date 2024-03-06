/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:29:13 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/06 13:56:27 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->n > stack_a->next->n)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_is_sorted(*stack_a))
	{
		ft_printf("%ssorted%s\n", GREEN, RESET_COLOR);
		ft_stackclear(&stack_b);
		return ;
	}
	else if (ft_stacklen(*stack_a) < 6)
		ft_printf("%ssmall%s not sorted%s\n", MAGENTA, YELLOW, RESET_COLOR);
	else
		ft_printf("%sbig%s not sorted%s\n", MAGENTA, YELLOW, RESET_COLOR);
}

// else
//     ft_sort_big(&stack_a);
//maybe don't separate the functions that much, and do other check-sorts here
//only inner operations of sorting do elsewhere.