/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:35:06 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/23 22:36:35 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int  error_check (char **arr)
{
    while (*arr)
    {
        //iterate through words after spaces
        //check if it is number (arg = word) = check for minus sign first, is after this all the signs are nums until space
        //check if it passed as num, if it is in the int range, if yes, then return OK 0 err
        //else - if err on any step, return 1 for err
            ft_printf ("%sErorr%s", RED, RESET_COLOR);
        return (0);
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (0);
    if(error_check (av[1]))
        return (0);
    // ft_printf ("ac: %d, name: %s, just smth: %d\n", ac, av[0], ft_isdigit(ac));
    return (0);
}