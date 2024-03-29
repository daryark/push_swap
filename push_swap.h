/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:36:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/18 18:43:45 by dyarkovs         ###   ########.fr       */
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

//process create
void	ft_process(char **av);
//handle errors
void	ft_error(char *message);
int		ft_is_numeric(char *s);
int		has_dup(t_stack *stack_a, long n);
int		not_int_range(long long n);
//utils
t_stack	*ft_stacknew(int n);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stack_addback(t_stack **stack, t_stack *new);
void	ft_new_node_back(t_stack **stack, int n);
void	ft_stackclean(t_stack **stack);
//sort helpers
int		is_sorted(t_stack *stack_a);
void	set_idx(t_stack **stack);
void	set_target_node(t_stack *stack_a, t_stack *stack_b);
void	set_cost(t_stack *stack);
t_stack	*final_cost(t_stack *stack_b);
int		position_both(t_stack *node_b);
//math
t_stack	*find_next_max(t_stack *stack);
t_stack	*find_min_node(t_stack *stack);
t_stack	*find_max_node(t_stack *stack);
int		ft_stacklen(t_stack *stack);
//sort
void	ft_sort(t_stack **stack_a);
void	sort3(t_stack **stack_a);
void	sort_big(t_stack **stack_a, t_stack **stack_b);
void	quick_sort(t_stack **stack_a, t_stack **stack_b);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);
//operation amnt + choice
void	do_dbl_rot_amnt(int amnt, t_stack *cheapest, t_stack **a, t_stack **b);
void	do_rot_b_amnt(t_stack *node, t_stack **stack_b);
void	do_rot_a_amnt(t_stack *node, t_stack **stack_a);
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

#endif