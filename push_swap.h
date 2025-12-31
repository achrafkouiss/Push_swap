/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:26:13 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/31 21:25:58 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    void    *content;
    ssize_t  pos;
    struct s_list *next; // need to know why i cannot put t_list *next
}   t_list;

void *push_swap(int argc, char *argv[]);
// void push_swap(int argc, char *argv[]);
ssize_t lstsize(t_list *lst);

char **ft_split(char *str, int i);
t_list *lsnew(void *content);
int    lstaddback(t_list **head, t_list *node);
int lstcheck(t_list *head, int (*ft)(char *));
int ft_atoi(char *str);

void *ft_free_array(char **arr);
void *ft_free_list(t_list *head);

t_list *parsing(int argc, char *argv[]);

void ft_putstr(char *str);

void ft_pos_list(t_list *lst, ssize_t index, ssize_t i, ssize_t len);

//swap functions
void pa(t_list **lst1, t_list **lst2);
void pb(t_list **lst1, t_list **lst2);

void ra(t_list **lst);
void rb(t_list **lst);

void rra(t_list **lst);
void rrb(t_list **lst);

void sa(t_list **lst);
void sb(t_list **lst);

void *ft_sort_small(t_list **stack_a, t_list **stack_b, ssize_t len);

//helper
int ft_is_listordered(t_list *lst);
ssize_t lstsize(t_list *lst);
ssize_t   ft_index_max(t_list *lst);
void    ft_swap_max(t_list **stack_a, t_list **stack_b, ssize_t len,  ssize_t index);


#endif