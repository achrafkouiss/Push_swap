/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 11:22:37 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/30 21:11:45 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(t_list **head)
{
    t_list *next;
    size_t len;

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


void    ft_push(t_list **lst1, t_list **lst2)
{
    t_list *new_list;

    if (!lst1 || !lst2 || (!*lst1 && !*lst2))
        return ;
    printf("xxxxxxxxxxxxxxxxxxx\n");
    new_list = (*lst1)->next;
    printf("xxxxxxxxxxxxxxxxxxx\n");
    if (!*lst2)
    {
        (*lst1)->next = NULL;
        *lst2 = *lst1;
        *lst1 = new_list;
        return ;
    }
    (*lst1)->next = *lst2;
    *lst2 = *lst1;
    *lst1 = new_list;
}

void pa(t_list **lst1, t_list **lst2)
{
    ft_push(lst1, lst2);
    write(1, "pa\n", 3);
}

void pb(t_list **lst1, t_list **lst2)
{
    ft_push(lst2, lst1);
    write(1, "pb\n", 3);
}

void ft_rotate(t_list **head)
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

void ft_reverse_rotate(t_list **head)
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
    write(1, "rra\n", 3);
}

void rrb(t_list **lst)
{
    ft_reverse_rotate(lst);
    write(1, "rrb\n", 3);
}
