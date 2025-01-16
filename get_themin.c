/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_themin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:22:37 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/16 12:29:44 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int minnumber(t_node **lst_a)
{
    if(!*lst_a || !(*lst_a)->next_node)
    {
        return 0;
    }
    t_node *current=*lst_a;
    int min=current->data;
    while(current)
    {
           if(min > current->data)
           {
                min =current->data;
           }
           current=current->next_node;
    }
    return min;
}
