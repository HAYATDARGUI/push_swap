/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:32:15 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/16 17:58:57 by hdargui          ###   ########.fr       */
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
// t_node	*ft_lstlast(t_node *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next_node != NULL)
// 		lst = lst->next_node;
// 	return (lst);
// }
void	ft_lstadd_back(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next_node = new;
}
int to_stack(int *new_int,int len, t_node **lst)
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
        if(!*lst)
        {
            *lst=new_one;
        }
        ft_lstadd_back(lst,new_one);
        i++;
     }
    return 1;
}