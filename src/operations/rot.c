/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:03:00 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/16 20:51:31 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// int	rotate(t_stack **stack)
// {
// 	t_stack	*append;

// 	if ((*stack) == NULL || (*stack)->next == NULL)
// 		return (0);
// 	append = *stack;
// 	ft_stacklast((*stack)->next)->next = append;
// 	*stack = append->next;
// 	append->next = NULL;
// 	return (1);
// }

int	rotate(t_stack **stack)
{
	t_stack	*new_head;
	t_stack	*head_last;

	new_head = NULL;
	head_last = NULL;
	if (ft_stacklen(*stack) < 2)
		return (0);
	if (*stack)
	{
		head_last = *stack;
		new_head = (*stack)->next;
		*stack = new_head;
		head_last->next = NULL;
		ft_stack_addback(stack, head_last);
	}
	return (1);
}

void	ra(t_stack **stack_a)
{
	if (rotate(stack_a))
		ft_printf ("ra\n");
}

void	rb(t_stack **stack_b)
{
	if (rotate(stack_b))
		ft_printf ("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if(rotate(stack_a) && rotate (stack_b))
		ft_printf ("rr\n");
}
