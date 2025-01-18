/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_themax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:28:24 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/17 16:53:13 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int maxnumber(t_node **lst_a)
{
    int pos=0;
    int savep;
    if(!*lst_a || !(*lst_a)->next_node)
    {
        return 0;
    }
    t_node *current=*lst_a;
    int max=current->data;
    savep=pos;
    while(current)
    {
           if(max < current->data)
           {
                max =current->data;
                savep=pos;
           }
           current=current->next_node;
           pos++;
    }
    return savep;
}
