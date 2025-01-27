/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:45:43 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/27 15:33:18 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	while (s1[i] && i < ft_strlen(s1))
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] && j < ft_strlen(s2))
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	free((void *)s1);
	s3[i] = '\0';
	return (s3);
}

int	stacksize(t_node *lst_a)
{
	t_node	*current;
	int		size;

	size = 0;
	current = lst_a;
	while (current)
	{
		size++;
		current = current->next_node;
	}
	return (size);
}

void	push_to_stack_b(t_node **lst_a, t_node **lst_b)
{
	int	size;
	int	min;
	int	max;

	size = stacksize(*lst_a);
	min = 0;
	max = (int)(0.048 * size + 10);
	while (*lst_a)
	{
		if ((*lst_a)->position >= min && (*lst_a)->position <= max)
		{
			pb(lst_a, lst_b, 1);
			min++;
			max++;
		}
		else if ((*lst_a)->position < min)
		{
			pb(lst_a, lst_b, 1);
			rb(lst_b, 1);
			min++;
			max++;
		}
		else if ((*lst_a)->position > max)
			ra(lst_a, 1);
	}
}

void	help_function(int max, t_node **lst_b, int size)
{
	while (max <= size)
	{
		rrb(lst_b, 1);
		max++;
	}
}

void	push_b_to_a(t_node **lst_a, t_node **lst_b)
{
	int	size;
	int	max;

	while (*lst_b)
	{
		size = stacksize(*lst_b);
		max = maxnumber(lst_b);
		max++;
		if ((max - 1) <= size / 2 && max != 1)
		{
			while (max != 1)
			{
				rb(lst_b, 1);
				max--;
			}
		}
		else if (max != 1)
			help_function(max, lst_b, size);
		pa(lst_a, lst_b, 1);
	}
}
