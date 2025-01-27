/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_themax_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:28:24 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/27 15:32:31 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/push_swap.h"

int	maxnumber(t_node **lst_a)
{
	t_node	*current;
	int		max;
	int		i;
	int		maxp;

	if (!*lst_a || !(*lst_a)->next_node)
	{
		return (0);
	}
	current = *lst_a;
	max = current->position;
	i = 0;
	maxp = 0;
	while (current)
	{
		if (max < current->position)
		{
			max = current->position;
			maxp = i;
		}
		current = current->next_node;
		i++;
	}
	return (maxp);
}
