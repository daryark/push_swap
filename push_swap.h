/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:36:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/05 16:28:24 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define RESET_COLOR "\033[0m"

#include <limits.h>
#include "libft/src/ft_printf/ft_printf.h"
#include "libft/libft.h"

typedef struct s_stack
{
    int                 n;   
    struct s_stack   *next;
}   t_stack;


//process create
void    ft_process(char **av);
void    ft_sort(t_stack **stack_a);
//sort
int     ft_is_sorted(t_stack *stack_a);

//utils
t_stack *ft_stacknew(int n);
t_stack *ft_stacklast(t_stack *stack);
void    ft_stack_addback(t_stack **stack, t_stack *new);
//cleaning
void    ft_stackclear(t_stack **stack);
void    ft_del_stacknode(t_stack *node);
//handle errors
void    ft_error(char *message);
int     ft_s_numeric(char *s);
int     has_dup(t_stack *stack_a, long n);
int     not_int_range(long n);

#endif