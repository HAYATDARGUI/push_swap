/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:15:52 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/16 17:56:30 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate_stack(t_node **lst)
{
    t_node *tmp1;
    t_node *tmp2;
    

    if(!*lst || !(*lst)->next_node)
    {
        return ;
    }
    tmp2=*lst;
    while(tmp2->next_node)
    {
        tmp2=((*lst)->next_node);
    }
    tmp1=tmp2;
    
    tmp2->prev_node->next_node=NULL;
    tmp1->prev_node = NULL;
    ft_lstadd_front(lst,tmp1);
}
void rra(t_node **lst_a,int i)
{
    reverse_rotate_stack(lst_a);
    if(i)
    {
        write(1, "ra", 2);
    }
}
void rrb(t_node **lst_b,int i)
{
    reverse_rotate_stack(lst_b);
    if(i)
    {
        write(1, "rb", 2);
    }
}
void rrr(t_node **lst_a, t_node **lst_b,int i)
{
    reverse_rotate_stack(lst_a);
    reverse_rotate_stack(lst_b);
    if(i)
    {
        write(1, "rrr", 3);
    }
}