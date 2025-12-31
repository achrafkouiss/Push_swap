/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:04:12 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 21:20:52 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_putchar(char c)
{
    write(2, &c, 1);
}

void ft_putstr(char *str)
{
    ssize_t i;

    if (!str)
        return ;
    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;   
    }
}