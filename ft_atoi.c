/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:40:40 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 21:27:27 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi(char *str)
{
    long nbr;
    long sign;
    size_t i;

    if (!str)
        return (2147483649);
    i = 0;
    nbr = 0;
    sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i])
    {
        nbr = (nbr * 10) + (str[i] - '0');
        if (((nbr * sign) < -2147483648) || ((nbr * sign) > 2147483647))
            return (2147483649);
        i++;
    }
    return (nbr * sign);
}
