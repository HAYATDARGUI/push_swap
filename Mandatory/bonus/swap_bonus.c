/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:33:36 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/26 15:22:17 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node **lst)
{
	t_node	*new_lst;

	if (!*lst || !(*lst)->next_node)
	{
		return ;
	}
	new_lst = (*lst)->next_node;
	(*lst)->next_node = new_lst->next_node;
	if (new_lst->next_node != NULL)
	{
		new_lst->next_node->prev_node = *lst;
	}
	new_lst->prev_node = NULL;
	new_lst->next_node = *lst;
	(*lst)->prev_node = new_lst;
	*lst = new_lst;
}

void	sa(t_node **lst, int i)
{
	swap(lst);
	if (i)
	{
		write(1, "sa\n", 3);
	}
}

void	sb(t_node **lst, int i)
{
	swap(lst);
	if (i)
	{
		write(1, "sb\n", 3);
	}
}

void	ss(t_node **lst_a, t_node **lst_b, int i)
{
	swap(lst_a);
	swap(lst_b);
	if (i)
	{
		write(1, "ss\n", 3);
	}
}
