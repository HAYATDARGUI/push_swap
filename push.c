/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:15:47 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/08 17:25:21 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_lstadd_front(t_node **lst, t_node *newn)
{
	if (!lst || !newn)
		return ;
	newn->next_node = *lst;
	*lst = newn;
}
void push_to_stack(t_node **lst1,t_node **lst2)
{
    t_node *tmp;
    if(!*lst2)
    {
        return;
    }

    tmp = *lst2;
    *lst2 = (*lst2)->next_node;
    if(*lst2)
    {
        (*lst2)->prev_node=NULL;
    }
    
    ft_lstadd_front(lst1,tmp);
}
void pa(t_node **lst_a, t_node **lst_b,int i)
{
    push_to_stack(lst_a, lst_b);
    if(i)
    {
        write(1,"pa",2);
    }
}
void pb(t_node **lst_a, t_node **lst_b,int i)
{
    push_to_stack(lst_b, lst_a);
    if(i)
    {
        write(1,"pb",2);
    }
}

