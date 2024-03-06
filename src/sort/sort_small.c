/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:24:16 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/06 17:42:48 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort3(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->n;
	b = (*stack_a)->next->n;
	c = (*stack_a)->next->next->n;
	if ((a > b && a < c)
		|| (a > b && b > c)
		|| (a < b && b > c))
		sa(stack_a);
	if (a < b && a > c)
		rra(stack_a);
	else if (a > c && c > b)
		ra(stack_a);
}

void	sort_small(t_stack **stack_a)
{
	int	len;

	len = ft_stacklen(*stack_a);
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort3(stack_a);
	//*just to show the sorted stack result, !not needed loop!
	while (*stack_a)
	{
		ft_printf("%ssorted: %d%s\n", GREEN, (*stack_a)->n, RESET_COLOR);
		*stack_a = (*stack_a)->next;
	}
}
