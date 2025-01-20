/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:15:52 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/20 16:19:55 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate_stack(t_node **lst)
{
    t_node *last_node;
    
    if(!*lst || !(*lst)->next_node)
    {
        return ;
    }
    last_node = *lst;
    while(last_node->next_node)
    {
        last_node=((last_node)->next_node);
    }
    t_node *tmp1prev=last_node->prev_node;
    ft_lstadd_front(lst, last_node);
    tmp1prev->next_node=NULL;
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