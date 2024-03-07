/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:36:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/07 13:26:37 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define RESET_COLOR "\033[0m"

# include <limits.h>
# include "libft/src/ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}	t_stack;

//process create
void	ft_process(char **av);
//sort
void	ft_sort(t_stack **stack_a);
int		ft_is_sorted(t_stack *stack_a);
void	sort_small(t_stack **stack_a);
void	sort3(t_stack **stack_a);
//operations
int		rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
int		rev_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
int		swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
int		push(t_stack **from, t_stack **to);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
//utils
t_stack	*ft_stacknew(int n);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stack_addback(t_stack **stack, t_stack *new);
int		ft_stacklen(t_stack *stack);
//cleaning
void	ft_stackclear(t_stack **stack);
void	ft_del_stacknode(t_stack *node);
//handle errors
void	ft_error(char *message);
int		ft_s_numeric(char *s);
int		has_dup(t_stack *stack_a, long n);
int		not_int_range(long n);

#endif