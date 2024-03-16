/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:36:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/15 23:39:21 by dyarkovs         ###   ########.fr       */
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
	int				i;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

//!delete later
void	print_stack(t_stack *stack_a);
//!
//process create
void	ft_process(char **av);
//handle errors
void	ft_error(char *message);
int		ft_is_numeric(char *s);
int		has_dup(t_stack *stack_a, long n);
int		not_int_range(long n);
//utils
t_stack	*ft_stacknew(int n);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stack_addback(t_stack **stack, t_stack *new);
int		ft_stacklen(t_stack *stack);
//sort helpers
void	set_idx(int stack_len, t_stack *stack);
void	set_target_node(t_stack *stack_a, t_stack *stack_b);
void	set_cost(t_stack *stack);
int		position_both(t_stack *node_b);
t_stack	*final_cost(t_stack *stack_b);
t_stack	*find_max(t_stack *stack);
int		is_sorted(t_stack *stack_a);
//sort
void	ft_sort(t_stack **stack_a);
void	sort3(t_stack **stack_a);
void	sort_big(t_stack **stack_a, t_stack **stack_b);
void	quick_sort(t_stack **stack_a, t_stack **stack_b);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);
void	do_dbl_rot_amnt(int amnt, t_stack *cheapest, t_stack **a, t_stack **b);
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
//cleaning
void	ft_stackclean(t_stack **stack);
void	ft_del_stacknode(t_stack *node);

#endif