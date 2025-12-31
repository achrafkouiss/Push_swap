/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsnew.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:07:25 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 18:55:49 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t ft_strlen(char *str)
{
    ssize_t i;

    if (!str)
        return (-1);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strdup(char *str)
{
    char *s;
    ssize_t len;
    ssize_t i;
    
    if (!str)
        return (NULL);
    len = ft_strlen(str) + 1;
    s = malloc(len);
    if (!s)
        return (NULL);
    i = 0;
    while (str[i])
    {
        s[i] = str[i];
        i++;
    }
    s[i] = '\0';
    return (s);
}

t_list *lsnew(void *content)
{
    t_list *node;
    char *str;

    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    str = ft_strdup(content);
    if (!str && content)
        return (NULL);
    node->content = str;
    node->pos = -1;
    node->next = NULL;
    return (node);
}