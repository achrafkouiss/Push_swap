/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:30:54 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 18:53:51 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_sort_two(t_list **stack)
{
    if ((*stack)->pos > (*stack)->next->pos)
        sa(stack);
}

static void ft_sort_three(t_list **stack_a)
{
    ssize_t a;
    ssize_t b;
    ssize_t c;

    if (!ft_is_listordered(*stack_a))
        return ;
    a = (*stack_a)->pos;
    b = (*stack_a)->next->pos;
    c = (*stack_a)->next->next->pos;
    if (b < a && b < c && a < c)
        sa(stack_a);
    else if( b < a && b < c && c < a)
        ra(stack_a);
    else if (c < a && c < b && a < b)
        rra(stack_a);
    else if (a < b && a < c && c < b)
    {
        rra(stack_a);
        sa(stack_a);
    }
    else
    {
        sa(stack_a);
        rra(stack_a);
    }
}

static void ft_sort_four(t_list **stack_a, t_list **stack_b, ssize_t len)
{
    ft_swap_max(stack_b, stack_a, len, 0);
    ft_sort_three(stack_a);
    pa(stack_b, stack_a);
    ra(stack_a);
}

static void ft_sort_five(t_list **stack_a, t_list **stack_b, ssize_t len)
{
    ft_swap_max(stack_b, stack_a, len, 0);
    ft_swap_max(stack_b, stack_a, len, 0);
    ft_sort_three(stack_a);
    pa(stack_b, stack_a);
    ra(stack_a);
    pa(stack_b, stack_a);
    ra(stack_a);
}

void *ft_sort_small(t_list **stack_a, t_list **stack_b, ssize_t len)
{
    if (len == 2)
        ft_sort_two(stack_a);
    else if (len == 3)
        ft_sort_three(stack_a);
    else if (len == 4)
        ft_sort_four(stack_a, stack_b, len);
    else if (len == 5)
        ft_sort_five(stack_a, stack_b, len);
    return (ft_free_list(*stack_a));
}