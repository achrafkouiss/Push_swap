/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 11:09:35 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/30 07:53:02 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_pos_list(t_list *lst, size_t index, size_t i, size_t len)
{
    t_list *current;
    t_list *smallest;

    while (i++ < len)
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
