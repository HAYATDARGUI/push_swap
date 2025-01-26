/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_themin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:22:37 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/26 13:41:22 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minnumber(t_node **lst_a)
{
	t_node	*current;
	int		min;
	int		i;
	int		minp;

	if (!*lst_a || !(*lst_a)->next_node)
	{
		return (0);
	}
	current = *lst_a;
	min = current->position;
	i = 0;
	minp = 0;
	while (current)
	{
		if (min > current->position)
		{
			min = current->position;
			minp = i;
		}
		current = current->next_node;
		i++;
	}
	return (minp);
}
