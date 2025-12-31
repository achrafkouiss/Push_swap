/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:23:43 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 18:52:49 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_fisr_sort(t_list **stack_a, t_list **stack_b, ssize_t len, ssize_t index)
{
    int chank;

    if (len <= 100)
        chank = 13;
    else
        chank = 32;
    while (index < len)
    {
        if ((*stack_a)->pos <= index + chank)
        {
            if (index <= (*stack_a)->pos)
                pb(stack_a, stack_b);
            else 
            {
                pb(stack_a, stack_b);
                rb(stack_b);
            }
            index++;
        }
        else
            ra(stack_a);
    }
}

static void    ft_final_swap(t_list **stack_a, t_list **stack_b, ssize_t len,  ssize_t index)
{
    if (!stack_b || !*stack_b)
		return ;
    len = lstsize(*stack_b);
    index = ft_index_max(*stack_b);
    if (index <= len / 2)
    {
        while (index > 0)
        {
            rb(stack_b);
            index--;
        }
    }
    else
    {
        while (index < len)
        {
            rrb(stack_b);
            index++;
        }     
    }
    pa(stack_b, stack_a);
}

void    *push_swap(int argc, char *argv[])
{
    t_list *stack_a;
    t_list *stack_b;
    ssize_t len;

    if (argc <= 2)
        return (NULL);
    stack_b = NULL;
    stack_a = parsing(argc, argv);
    if (!stack_a)
    {
        ft_putstr("error\n");
        return (NULL);
    }
    len = lstsize(stack_a);
    ft_pos_list(stack_a, 0, 0, len);
    if (!ft_is_listordered(stack_a))
        return (ft_free_list(stack_a));
    if (len <= 5)
        return (ft_sort_small(&stack_a, &stack_b, len));
    ft_fisr_sort(&stack_a, &stack_b, len, 0);
    while (stack_b)
            ft_final_swap(&stack_a, &stack_b, 0, 0);
    ft_free_list(stack_b);
    ft_free_list(stack_a);
} 

int main(int argc, char *argv[])
{
    push_swap(argc, argv);
}