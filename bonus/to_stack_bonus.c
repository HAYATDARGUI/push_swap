/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stack_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:32:15 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/27 18:50:56 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*ft_lstnew(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = content;
	node->next_node = NULL;
	node->position = 0;
	node->prev_node = NULL;
	return (node);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last_node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->prev_node = NULL;
		new->next_node = NULL;
	}
	else
	{
		last_node = ft_lstlast(*lst);
		last_node->next_node = new;
		new->prev_node = last_node;
		new->next_node = NULL;
	}
}

int	to_stack(int *new_int, int len, t_node **lst_a)
{
	int		i;
	int		j;
	t_node	*new_one;

	i = 0;
	j = 0;
	while (i < len)
	{
		new_one = ft_lstnew(new_int[i]);
		if (!new_one)
			return (free(new_int), free_stack(lst_a), 0);
		j = 0;
		while (j < len)
		{
			if (new_int[i] > new_int[j++])
				new_one->position++;
		}
		if (!*lst_a)
			*lst_a = new_one;
		else
			ft_lstadd_back(lst_a, new_one);
		i++;
	}
	free(new_int);
	return (1);
}
