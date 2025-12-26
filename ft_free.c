/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:19:36 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/26 08:42:27 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void *ft_free_array(char **arr)
{
    int i;
    
    if (!arr)
        return (NULL);
    i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
    return (NULL);
}

void *ft_free_list(t_list *head)
{
    int i;
    t_list *current;
    t_list *previous;
    
    if (!head)
        return (NULL);
    current = head;
    while (current)
    {
        free(current->content);
        previous = current;
        current = current->next;
        free(previous);
    }
    return (NULL);
}