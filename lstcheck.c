/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:05:34 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 18:52:10 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_repeat(t_list *head, int nbr,ssize_t index)
{
    ssize_t i;
    t_list *current;

    i = 0;
    current = head;
    while (i < index)
    {
        if (nbr == *((int *)current->content))
            return (0);
        current = current->next;
        i++;
    }
    return (1);
}

void *ft_copy_mem(void *dest, void *src, ssize_t count)
{
    unsigned char *s;
    unsigned char *s2;
    ssize_t i;

    if (!dest || !src)
        return (NULL);
    s =  (unsigned char *)src;
    s2 = (unsigned char *)dest;
    i = 0;
    while (i  < count)
    {
        s2[i] = s[i];
        i++;
    }
    return (dest);
}

int *allo_nbr(int nbr)
{
    int *n;

    n = malloc(sizeof(int));
    if (!n)
        return (NULL);
    n = ft_copy_mem(n, &nbr, 4);
    if (!n)
        return (NULL);
    return (n);
}

int lstcheck(t_list *head, int (*ft)(char *, int *))
{
    t_list *current;
    ssize_t index;
    int nbr;
    int bool;

    index = 0;
    bool = 0;
    if (!head || !ft)
        return (0);
    current = head;
    while (current)
    {
        nbr = ft(current->content, &bool);
        if (bool)
            return (0);
        if (!check_repeat(head, nbr, index))
            return (0);
        free(current->content);
        current->content = allo_nbr(nbr);
        if (!current->content)
            return (0);
        index++;
        current = current->next;
    }
    return (1);
}
