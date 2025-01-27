/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:15:47 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/27 15:32:47 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/push_swap.h"

void	ft_lstadd_front(t_node **lst, t_node *newn)
{
	if (!lst || !newn)
		return ;
	newn->next_node = *lst;
	if (*lst)
		(*lst)->prev_node = newn;
	*lst = newn;
	newn->prev_node = NULL;
}

void	push_to_stack(t_node **lst1, t_node **lst2)
{
	t_node	*tmp;

	if (!*lst2)
	{
		return ;
	}
	tmp = *lst2;
	*lst2 = (*lst2)->next_node;
	if (*lst2)
	{
		(*lst2)->prev_node = NULL;
	}
	ft_lstadd_front(lst1, tmp);
}

void	pa(t_node **lst_a, t_node **lst_b, int i)
{
	push_to_stack(lst_a, lst_b);
	if (i)
	{
		write(1, "pa\n", 3);
	}
}

void	pb(t_node **lst_a, t_node **lst_b, int i)
{
	push_to_stack(lst_b, lst_a);
	if (i)
	{
		write(1, "pb\n", 3);
	}
}
