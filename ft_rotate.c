/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:15:47 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 17:16:43 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_rotate(t_list **head)
{
    t_list *new_head;
    t_list *tmp;

    if (!head || !*head || !(*head)->next)
        return ;
    tmp = *head;
    *head = (*head)->next;
    new_head = *head;
    tmp->next = NULL;
    while (new_head->next)
        new_head = new_head->next;    
    new_head->next = tmp;
}

void ra(t_list **lst)
{
    ft_rotate(lst);
    write(1, "ra\n", 3);
}

void rb(t_list **lst)
{
    ft_rotate(lst);
    write(1, "rb\n", 3);
}