/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsnew.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:07:25 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/26 09:08:35 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strdup(char *str)
{
    char *s;
    size_t len;
    size_t i;
    
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
    node->next = NULL;
    return (node);
}