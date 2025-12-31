/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 11:22:37 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 18:50:40 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_swap(t_list **head)
{
    t_list *next;
    ssize_t len;

    if (!head || !*head)
        return ;
    len = lstsize(*head);
    if (len <= 1)
        return ;
    next = (*head)->next;
    (*head)->next = next->next;
    next->next = (*head);
    (*head) = next;
}

void sa(t_list **lst1)
{
    ft_swap(lst1);
    write(1, "sa\n", 3);
}

void sb(t_list **lst1)
{
    ft_swap(lst1);
    write(1, "sb\n", 3);
}
