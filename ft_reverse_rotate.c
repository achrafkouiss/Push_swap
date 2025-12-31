/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:17:05 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 17:17:21 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_reverse_rotate(t_list **head)
{
    t_list *prev;
    t_list *curr;

    if (!head || !*head || !(*head)->next)
        return ;
    prev = NULL;
    curr = *head;
    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr->next = *head;
    *head = curr;
}

void rra(t_list **lst)
{
    ft_reverse_rotate(lst);
    write(1, "rra\n", 4);
}

void rrb(t_list **lst)
{
    ft_reverse_rotate(lst);
    write(1, "rrb\n", 4);
}
