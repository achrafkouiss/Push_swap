/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:35:37 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 18:51:12 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_listordered(t_list *lst)
{
    ssize_t i;

    i = 0;
    while (lst)
    {
        if (lst->pos != i)
            return (1);
        lst = lst->next;
        i++;
    }
    return (0);
}

ssize_t lstsize(t_list *lst)
{
    ssize_t index;

    index = 0;
    while (lst)
    {
        lst = lst->next;
        index++;
    }
    return (index);
}

ssize_t   ft_index_max(t_list *lst)
{
    ssize_t i;
    ssize_t index;
    ssize_t nbr;
    
    index = 0;
    i = 0;
    nbr = lst->pos;
    lst = lst->next;
    while (lst)
    {
        if (nbr < lst->pos)
        {
            index =  i + 1;
            nbr = lst->pos;
        }
        lst = lst->next;
        i++;
    }
    return (index);
}

void    ft_swap_max(t_list **stack_a, t_list **stack_b, ssize_t len,  ssize_t index)
{
    if (!stack_b || !*stack_b)
		return ;
    len = lstsize(*stack_b);
    index = ft_index_max(*stack_b);
    if (index <= len / 2)
    {
        while (index > 0)
        {
            ra(stack_b);
            index--;
        }
    }
    else
    {
        while (index < len)
        {
            rra(stack_b);
            index++;
        }     
    }
    pb(stack_b, stack_a);
}
