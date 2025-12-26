/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:26:13 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/26 08:17:24 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void    *content;
    struct s_list *next; // need to know why i cannot put t_list *next
}   t_list;

char **ft_split(char *str, int i);
t_list *lsnew(void *content);
int    lstaddback(t_list **head, t_list *node);
int lstcheck(t_list *head, int (*ft)(char *, int *));
int ft_atoi(char *str, int *bool);

void *ft_free_array(char **arr);
void *ft_free_list(t_list *head);



#endif