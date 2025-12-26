/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <akouiss@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:08:04 by akouiss           #+#    #+#             */
/*   Updated: 2025/12/26 09:09:58 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *split_to_list(int argc, char *argv[])
{
    int i;
    int z;
    char **arr;
    t_list *node;
    t_list *head;

    i = 1;
    head = NULL;
    while (i < argc && argv)
    {
        z = 0;
        arr = ft_split(argv[i++], 0);
        if (!arr)
            return (ft_free_array(arr), ft_free_list(head));
        while (arr[z])
        {
            node = lsnew(arr[z++]);
            if (!node)
                return (ft_free_array(arr), ft_free_list(head));
            if (lstaddback(&head, node))
                return(ft_free_array(arr), ft_free_list(head), ft_free_list(node));
        }
        ft_free_array(arr);
    }
    return (head);
}

int check_content(char *str)
{
    int i;

    i = 0;
    if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
        i++;
    else
        return (0);
    if (str[i] == '+' || str[i] == '-')
        return (0);
    if ((str[i - 1] == '+' || str[i - 1] == '-') && !str[i])
        return (0);
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int  check_list(t_list *head, int (*ft)(char *))
{
    t_list *current;

    if (!head || !ft)
        return (0);
    current = head;
    while (current)
    {
        if (!ft(current->content))
            return (0);
        current = current->next;
    }
    return (1);
}

t_list *parsing(int argc, char *argv[])
{
    t_list *head;
    int bool;

    head = split_to_list(argc, argv);
    bool = check_list(head, check_content);
    if (!bool)
    {
        ft_free_list(head);
        return (NULL);
    }
    if (!lstcheck(head, ft_atoi))
    {
        ft_free_list(head);
        return (NULL);
    }
    ft_free_list(head);
    return (head);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
        return (0);
    if (!parsing(argc, argv))
        printf("not working");
    else
    {
        printf("working");
    }
}
