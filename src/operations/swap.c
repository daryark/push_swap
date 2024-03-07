/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:49:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/07 13:28:14 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*prev_head;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return (0);
	prev_head = *stack; //preserve head;
	*stack = (*stack)->next; //move to new head
	prev_head->next = (*stack)->next; //prev head next is third elem
	(*stack)->next = prev_head; //new head next reassign to prev head
	return (1);
}

void	sa(t_stack **stack_a)
{
	if (swap(stack_a))
		ft_printf ("sa\n");
}

void	sb(t_stack **stack_b)
{
	if (swap(stack_b))
		ft_printf ("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (swap(stack_a) || swap(stack_b))
		ft_printf ("ss\n");
}
