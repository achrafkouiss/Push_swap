/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:23:43 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/30 11:05:28 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// max min in toi is not handled
#include "push_swap.h"

size_t lstsize(t_list *lst)
{
    size_t index;

    index = 0;
    while (lst)
    {
        lst = lst->next;
        index++;
    }
    return (index);
}

void    ft_fisr_sort(t_list **stack_a, t_list **stack_b, size_t len, int chank, size_t index)
{
    t_list *current;

    current = *stack_a;
    while (index < len)
    {
        if (current->pos <= index + chank)
        {
            ft_push(stack_a, stack_b);
            if (index <= current->pos)
                write(1, "pb\n", 3);
            else 
            {
                ft_rotate(stack_b);
                write(1, "pb\n", 3);
                write(1, "rb\n", 3);
            }
            index++;
        }
        else
        {
                ft_rotate(stack_a);
                write(1, "ra\n", 3);
        }
        current = *stack_a;
    }
}

size_t   ft_index_max(t_list *lst)
{
    size_t i;
    size_t index;
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

void    ft_final_swap(t_list **stack_a, t_list **stack_b, size_t len,  size_t index)
{
    if (!stack_b || !*stack_b)
		return ;
    len = lstsize(*stack_b);
    index = ft_index_max(*stack_b);
    if (index <= len / 2)
    {
        while (index > 0)
        {
            ft_rotate(stack_b);
            write(1, "rb\n", 3);
            index--;
        }
    }
    else
    {
        while (index < len)
        {
            ft_reverse_rotate(stack_b);
            write(1, "rrb\n", 4);
            index++;
        }     
    }
    ft_push(stack_b, stack_a);
    write(1, "pa\n", 3);
}

t_list *push_swap(int argc, char *argv[])
{
    t_list *stack_a;
    t_list *stack_b;
    size_t len;
    int chank;

    if (len <= 100)
        chank = 11;
    else
        chank = 25;
    stack_b = NULL;
    stack_a = parsing(argc, argv);
    if (!stack_a)
    {
        ft_putstr("error");
        return (NULL);
    }
    len = lstsize(stack_a);
    ft_pos_list(stack_a, 0, 0, len);
    ft_fisr_sort(&stack_a, &stack_b, len, chank, 0);
    while (stack_b)
        ft_final_swap(&stack_a, &stack_b, 0, 0);
    ft_free_list(stack_a);
    return (stack_b);
} 

int main(int argc, char *argv[])
{
    push_swap(argc, argv);
}