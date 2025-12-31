/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:23:43 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 10:18:13 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    if (len <= 100)
        chank = 3;
    else
        chank = 32;
    current = *stack_a;
    while (index < len)
    {
        if (current->pos <= index + chank)
        {
            // ft_push(stack_a, stack_b);
            if (index <= current->pos)
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

int ft_is_listordered(t_list *lst)
{
    size_t i;

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
// void *sort_two(t_list **stack_a)
// {
//     t_list *next;

//     next = (*stack_a)->next;
//     if ((*stack_a)->pos < (*next)->pos)
// }
// void *sort_small(t_list **stack_a, t_list **stack_b, size_t len)
// {
    
// }

void    *push_swap(int argc, char *argv[])
{
    t_list *stack_a;
    t_list *stack_b;
    size_t len;
    int chank;

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
    // if (len <= 5)
    //     return (ft_sort_small());
    printf("len = %ld\n", len);
    ft_fisr_sort(&stack_a, &stack_b, len, chank, 0);
    while (stack_b)
            ft_final_swap(&stack_a, &stack_b, 0, 0);
    ft_free_list(stack_b);
    ft_free_list(stack_a);
} 

int main(int argc, char *argv[])
{
    push_swap(argc, argv);
}