/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:29:13 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/10 18:38:40 by dyarkovs         ###   ########.fr       */
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
	int		len;

	stack_b = NULL;
	if (ft_is_sorted(*stack_a))
	{
		ft_printf("%sSORTED%s\n", GREEN, RESET_COLOR);
		ft_stackclear(&stack_b);
		return ;
	}
	len = ft_stacklen(*stack_a);
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort3(stack_a);
	else
		sort_big(len, stack_a, &stack_b);
	while (*stack_a)
	{
		ft_printf("%ssorted: %d%s\n", GREEN, (*stack_a)->n, RESET_COLOR);
		*stack_a = (*stack_a)->next;
	}
}
