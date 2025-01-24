/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_themax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:28:24 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/21 17:08:27 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int maxnumber(t_node **lst_a)
{
    if(!*lst_a || !(*lst_a)->next_node)
    {
        return 0;
    }
    t_node *current=*lst_a;
    int max=current->position;
    int i=0;
    int maxp=0;
    while(current)
    {
           if(max < current->position)
           {
                max =current->position;
                maxp=i;
           }
           current=current->next_node;
           i++;
    }
    return maxp;
}
