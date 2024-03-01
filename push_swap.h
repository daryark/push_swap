/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:36:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/01 22:28:01 by dyarkovs         ###   ########.fr       */
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

// typedef struct  s_atoi
// {
//     long n;
//     int err;
// }   t_atoi;

//process create
void    ft_process(char **av);

//utils
t_stack *ft_stacknew(int n);
t_stack *ft_stacklast(t_stack *stack);
void    ft_stack_addback(t_stack **stack, t_stack *new);
// t_atoi  ft_safe_atoi(const char *s);
void    ft_error(char *message);
int     ft_s_numeric(char *s);
int has_duplicate (t_stack *stack_a, int n);
int not_int_range(long n);

#endif