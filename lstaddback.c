/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstaddback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:09:01 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 20:53:55 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    lstaddback(t_list **head, t_list *node)
{
    t_list *current;

    if (!head || !node)
        return (1);
    if (!*head)
    {
        *head = node;
        return (0);
    }
    current = *head;
    while (current->next)
        current = current->next;
    current->next = node;
    return (0);
}