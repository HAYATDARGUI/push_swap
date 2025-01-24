/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_themin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:22:37 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/21 17:37:02 by hdargui          ###   ########.fr       */
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
    int min=current->position;
    int i=0;
    int minp=0;
    while(current)
    {
           if(min > current->position)
           {
                min =current->position;
                minp=i;
           }
           current=current->next_node;
           i++;
    }
    return minp;
}
