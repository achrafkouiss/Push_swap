/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:05:34 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 21:25:26 by akouiss          ###   ########.fr       */
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

int *allo_nbr(int nbr)
{
    int *n;

    n = malloc(sizeof(int));
    if (!n)
        return (NULL);
    *n = nbr;
    return (n);
}

int lstcheck(t_list *head, int (*ft)(char *))
{
    t_list *current;
    ssize_t index;
    int nbr;

    index = 0;
    if (!head || !ft)
        return (0);
    current = head;
    while (current)
    {
        nbr = ft(current->content);
        if (nbr == 2147483649)
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
