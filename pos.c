/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 11:09:35 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 18:52:31 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_pos_list(t_list *lst, ssize_t index, ssize_t i, ssize_t len)
{
    t_list *current;
    t_list *smallest;

    while (i++ < len && lst)
    {
        current = lst;
        while (current)
        {
            if (current->pos == -1)
            {
                smallest = current;
                current = lst;
                break ;
            }
            current = current->next;
        }
        while (current)
        {
            if ((*(int *)(smallest->content) > *(int *)(current->content)) && (current->pos == -1))
                smallest = current;   
            current = current->next;
        }
        smallest->pos = index++;
    }
}
