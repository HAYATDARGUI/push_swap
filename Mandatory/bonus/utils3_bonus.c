/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:05:03 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/26 16:15:17 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	l;

	l = ft_strlen(s1);
	i = 0;
	s2 = malloc(sizeof(char) * (l + 1));
	if (s2 == NULL)
	{
		return (NULL);
	}
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	b = (unsigned char *)s2;
	a = (unsigned char *)s1;
	i = 0;
	if (!a && !b)
		return (0);
	while ((a[i] != '\0' || b[i] != '\0') && n > i)
	{
		if (a[i] != b[i])
		{
			if (a[i] > b[i])
				return (1);
			else if (a[i] < b[i])
				return (-1);
		}
		i++;
	}
	return (0);
}

int	deja_vu(t_node *lst_a)
{
	if (!lst_a)
	{
		return (0);
	}
	while (lst_a->next_node)
	{
		if (lst_a->data > lst_a->next_node->data)
		{
			return (0);
		}
		lst_a = lst_a->next_node;
	}
	return (1);
}

void	help_function2(t_node **lst_a)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = (*lst_a)->position;
	nb2 = (*lst_a)->next_node->position;
	nb3 = (*lst_a)->next_node->next_node->position;
	if (nb1 > nb2 && nb3 > nb1)
		sa(lst_a, 1);
	else if (nb2 > nb3 && nb3 > nb1)
	{
		rra(lst_a, 1);
		sa(lst_a, 1);
	}
	else if (nb1 > nb3 && nb3 > nb2)
	{
		rra(lst_a, 1);
		rra(lst_a, 1);
	}
}
