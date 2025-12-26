/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:08:47 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/25 13:14:25 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_count_word(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (str[i])
            count++;
        while (str[i] != ' ' && str[i])
            i++;
    }
    return (count);
}

int ft_wordlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != ' ' && str[i])
        i++;
    return (i);    
}

char *ft_allo(char *str)
{
    int i;
    char *arr;
    int len;

    if (!str)
        return (NULL);
    len = ft_wordlen(str) + 1;
    arr = malloc(len);
    if (!arr)
        return (NULL);
    i = 0;
    while (str[i] != ' ' && str[i])
    {
        arr[i] = str[i];
        i++;
    }
    arr[i] = '\0';
    return (arr);
}

void *ft_free(char **arr, int z)
{
    int i;
    
    if (!arr)
        return (NULL);
    i = 0;
    while (i < z)
        free(arr[i++]);
    free(arr);
    return (NULL);
}

char **ft_split(char *str, int i)
{
    char **arr;
    int z;
    
    if (!str)
        return (NULL);
    arr = malloc(sizeof(char *) * (ft_count_word(str) + 1));
    if (!arr)
        return (NULL);
    z = 0;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (str[i])
        {
            arr[z] = ft_allo(&str[i]); 
            if (!arr[z++])
                return (ft_free(arr, z - 1));
        }
        while (str[i] != ' ' && str[i])
            i++;
    }
    arr[z] = NULL;
    return (arr);
}
