/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:15:52 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/27 18:50:35 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate_stack(t_node **lst)
{
	t_node	*last_node;
	t_node	*tmp1prev;

	if (!*lst || !(*lst)->next_node)
	{
		return ;
	}
	last_node = *lst;
	while (last_node->next_node)
	{
		last_node = ((last_node)->next_node);
	}
	tmp1prev = last_node->prev_node;
	ft_lstadd_front(lst, last_node);
	tmp1prev->next_node = NULL;
}

void	rra(t_node **lst_a, int i)
{
	reverse_rotate_stack(lst_a);
	if (i)
	{
		write(1, "rra\n", 4);
	}
}

void	rrb(t_node **lst_b, int i)
{
	reverse_rotate_stack(lst_b);
	if (i)
	{
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_node **lst_a, t_node **lst_b, int i)
{
	reverse_rotate_stack(lst_a);
	reverse_rotate_stack(lst_b);
	if (i)
	{
		write(1, "rrr\n", 4);
	}
}
