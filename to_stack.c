/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:32:15 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/20 15:12:05 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*node;

	node = malloc (sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = content;
	node->next_node = NULL;
    node-> position = 0;
    node-> prev_node=NULL;
    
	return (node);
}
void	ft_lstadd_back(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
    {
		*lst = new;
        new->prev_node=NULL;
        new->next_node = NULL; 
    }
	else
    {
        t_node *last_node=ft_lstlast(*lst);
		last_node->next_node = new;
        new->prev_node=last_node; 
        new->next_node = NULL;
    }
}
int to_stack(int *new_int,int len, t_node **lst_a)
{
     int i=0;
     int j=0;
     t_node *new_one;
     while(i < len)
     {
        new_one=ft_lstnew(new_int[i]);
        if(!new_one)
        {
            return 0;
        }
        j=0;
        while(j<len)
        {
            if(new_int[i] > new_int[j++])
            {
                new_one->position++;
            }
        }
        if(!*lst_a)
        {
            *lst_a=new_one;
        }
        ft_lstadd_back(lst_a,new_one);
        i++;
     }
    return 1;
}
