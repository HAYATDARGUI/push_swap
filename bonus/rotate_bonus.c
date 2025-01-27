/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:31:27 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/27 18:50:39 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next_node)
		lst = lst->next_node;
	return (lst);
}

void	rotate_stack(t_node **lst)
{
	t_node	*tmp;

	if (!*lst || !(*lst)->next_node)
	{
		return ;
	}
	tmp = (*lst);
	(*lst) = (*lst)->next_node;
	(*lst)->prev_node = NULL;
	ft_lstadd_back(lst, tmp);
}

void	ra(t_node **lst_a, int i)
{
	rotate_stack(lst_a);
	if (i)
	{
		write(1, "ra\n", 3);
	}
}

void	rb(t_node **lst_b, int i)
{
	rotate_stack(lst_b);
	if (i)
	{
		write(1, "rb\n", 3);
	}
}

void	rr(t_node **lst_b, t_node **lst_a, int i)
{
	rotate_stack(lst_a);
	rotate_stack(lst_b);
	if (i)
	{
		write(1, "rr\n", 3);
	}
}
