/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:04:06 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/08 12:45:53 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	push(t_stack **from, t_stack **to)
{
	t_stack	*head_to;

	if ((*from) == NULL)
		return (0);
	head_to = *to;
	*to = *from;
	*from = (*from)->next;
	(*to)->next = head_to;
	return (1);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push (stack_b, stack_a))
		ft_printf ("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push (stack_a, stack_b))
		ft_printf ("pb\n");
}


