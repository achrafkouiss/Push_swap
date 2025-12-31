/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:15:05 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 17:15:31 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_push(t_list **lst1, t_list **lst2)
{
    t_list *new_list;

    if (!lst1 || !lst2 || (!*lst1 && !*lst2))
        return ;
    new_list = (*lst1)->next;
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
    ft_push(lst1, lst2);
    write(1, "pb\n", 3);
}