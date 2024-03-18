/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:29:13 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/18 18:01:49 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort3(t_stack **stack_a)
{
	if (((*stack_a)->n < (*stack_a)->next->next->n
			&& (*stack_a)->next->n > (*stack_a)->next->next->n)
		|| ((*stack_a)->n > (*stack_a)->next->n
			&& (*stack_a)->n < (*stack_a)->next->next->n)
		|| ((*stack_a)->n > (*stack_a)->next->n
			&& (*stack_a)->next->n > (*stack_a)->next->next->n))
		sa(stack_a);
	if ((*stack_a)->n < (*stack_a)->next->n
		&& (*stack_a)->n > (*stack_a)->next->next->n)
		rra(stack_a);
	else if ((*stack_a)->n > (*stack_a)->next->next->n
		&& (*stack_a)->next->next->n > (*stack_a)->next->n)
		ra(stack_a);
}

int	is_sorted(t_stack *stack_a)
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
	if (is_sorted(*stack_a))
		return ;
	len = ft_stacklen(*stack_a);
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort3(stack_a);
	else
		sort_big(stack_a, &stack_b);
	ft_stackclean(&stack_b);
}
