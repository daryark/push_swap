/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:21:01 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/16 20:50:13 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*new_head;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return (0);
	head = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	new_head = (*stack)->next;
	(*stack)->next = NULL;
	new_head->next = head;
	*stack = new_head;
	return (1);
}

void	rra(t_stack **stack_a)
{
	if (rev_rotate(stack_a))
		ft_printf ("rra\n");
}

void	rrb(t_stack **stack_b)
{
	if (rev_rotate(stack_b))
		ft_printf ("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (rev_rotate(stack_a) && rev_rotate(stack_b))
		ft_printf ("rrr\n");
}
