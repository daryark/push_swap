/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:24:16 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/12 18:32:14 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// void	sort5(t_stack **stack_a, t_stack **stack_b)
// {
// 	//?try to find out if we can rotate both stacks on some operation!!
// 	//pb pb
// 	//sort3 other 3 elems in stack_a
// 	//find the place for elem in stack_b before pushing back
// 	//pa
// 	//rotate to fit next elem from stack_b
// 	//pb
// 	//rotate to the right position
// 	//clean stack_b
// }

// void	sort4(t_stack **stack_a, t_stack **stack_b)
// {
// 	//pb
// 	//sort3 other 3 elems in stack_a
// 	//find the place for elem in stack_b before pushing back
// 	//pa
// 	//rotate to right position
// 	//clean stack_b
// 	t_stack	*head;

// 	head = *stack_a;
// 	pb(stack_a, stack_b);
// 	sort3(stack_a);
// 	while ((*stack_a))
// 	{
// 		(*stack_a)->gap = (*stack_b)->n - (*stack_a)->n;
// 		(*stack_a) = (*stack_a)->next;
// 	}

// }

void	sort3(t_stack **stack_a)
{
	if (((*stack_a)->n < (*stack_a)->next->next->n
			&& (*stack_a)->next->n > (*stack_a)->next->next->n) // 1 3 2
		|| ((*stack_a)->n > (*stack_a)->next->n
			&& (*stack_a)->n < (*stack_a)->next->next->n) //2 1 3
		|| ((*stack_a)->n > (*stack_a)->next->n
			&& (*stack_a)->next->n > (*stack_a)->next->next->n)) // 3 2 1
		sa(stack_a);
	if ((*stack_a)->n < (*stack_a)->next->n
		&& (*stack_a)->n > (*stack_a)->next->next->n) //2 3 1
		rra(stack_a);
	else if ((*stack_a)->n > (*stack_a)->next->next->n
		&& (*stack_a)->next->next->n > (*stack_a)->next->n) // 3 1 2
		ra(stack_a);
}

void	quick_sort(int stack_len, t_stack **stack_a, t_stack **stack_b)
{
	int	mid;

	mid = stack_len / 2;
	while (stack_len > 3)
	{
		ft_printf("----------------------\nstacklen: %d\n", stack_len);
		if (stack_len > mid)
		{
			if ((*stack_a)->i <= mid)
			{
				pb(stack_a, stack_b);
				stack_len--;
			}
			else
				ra(stack_a);
		}
		else
		{
			mid /= 2;
			set_idx(stack_len, *stack_a);
			ft_printf("mid: %d\n", mid);
		}
	}
}

void	refresh_data(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
	ft_printf("refresh data\n");
}

void	sort_big(int stack_len, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max;

	max = find_max(*stack_a);
	ft_printf("sort big, max: %d\n", max->n);

	quick_sort(stack_len, stack_a, stack_b);
	sort3(stack_a);
	refresh_data(stack_a, stack_b);
}
