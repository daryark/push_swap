/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:04:52 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/17 21:06:18 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"


int	find_min(t_stack **stack)
{
	t_stack	*head;
	int		min;

	head = *stack;
	min = INT_MAX;
	while (head)
	{
		if (head->n < min)
		{
			min = head->n;
		}
		head = head->next;
	}
	return (min);
}

int	get_min_val(t_stack **stack, int min, int index)
{
	int		min2;
	t_stack	*head;

	head = *stack;
	min2 = min;
	while (head)
	{
		if (head->n > min)
		{
			min2 = head->n;
			break ;
		}
		head = head->next;
	}
	head = *stack;
	while (head)
	{
		if (head->n > min && head->n <= min2)
		{
			min2 = head->n;
			head->i = index;
		}
		head = head->next;
	}
	return (min2);
}

// void	set_idx(t_stack **stack)
// {
// 	int		index;
// 	int		min;
// 	t_stack	*head;

// 	index = 1;
// 	head = *stack;
// 	min = find_min(&head);
// 	while (index < ft_stacklen(*stack))
// 	{
// 		min = get_min_val(&head, min, index);
// 		index++;
// 	}
// }

void	reset_idx(t_stack *stack)
{
	while (stack)
	{
		stack->i = 0;
		stack = stack->next;
	}
}

// t_stack	*find_max(t_stack *stack)
// {
// 	t_stack	*new_min_node;
// 	int		stack_len;

// 	new_min_node = NULL;
// 	stack_len = ft_stacklen(stack);
// 	while (stack && stack->i != stack_len)
// 		stack = stack->next;
// 	if (stack)
// 		new_min_node = stack;
// 	while (stack)
// 	{
// 		if (new_min_node->n < stack->n && stack->i == 0)
// 			new_min_node = stack;
// 		stack = stack->next;
// 	}
// 	return (new_min_node);
// }

//chooses max from non set idxs, so the last max is the pre smallest - 1 idx, 0 idx leaves 0.
t_stack	*find_next_max(t_stack *stack)
{
	t_stack	*new_max_node;

	new_max_node = NULL;
	while (stack && stack->i != 0)
		stack = stack->next;
	if (stack)
		new_max_node = stack;
	while (stack)
	{
		if (new_max_node->n < stack->n && stack->i == 0)
			new_max_node = stack;
		stack = stack->next;
	}
	return (new_max_node);
}

void	set_idx(t_stack **stack)
{
	// t_stack *head;
	t_stack	*max_node;
	// t_stack	*curr_node;
	// int		diff;
	int		stack_len;

	stack_len = ft_stacklen(*stack);
	reset_idx(*stack);
	max_node = NULL;
	while (--stack_len)
	{

		max_node = find_next_max(*stack);
		// if (max_node)
			max_node->i = stack_len;
		// else
		// 	ft_printf("%s.%s\n", RED, RESET_COLOR);
			// ft_printf("max node: %d\n", max_node->n);
		// max_node = *stack;
		// diff = INT_MAX;
		// head = *stack;
		// while (head)
		// {
		// 	if ((max_node->n - head->n) < diff && head->i == 0)
		// 	{
		// 		diff = (max_node->n - head->n);
		// 		curr_node = head;
		// 	}
		// 	head = head->next;
		// }
		// max_node = curr_node;
	}
}

	// head = stack;
	// while (head)
	// {
	// 	ft_printf("%d, ", head->n);
	// 	head = head->next;
	// }
	// printf("\n");