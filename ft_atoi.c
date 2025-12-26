/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:40:40 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/25 11:36:22 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi(char *str, int *bool)
{
    long nbr;
    long sign;
    size_t i;

    i = 0;
    nbr = 0;
    sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if (sign == '-')
            sign = -1;
        i++;
    }
    while (str[i])
    {
        nbr = (nbr * 10) + (str[i] - '0');
        if ((nbr * sign) < -2147483648 || (nbr * sign) > 2147483647)
        {
            *bool = 1;
            return (0);
        }
        i++;
    }
    return (nbr * sign);
}
