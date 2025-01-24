/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:45:43 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/24 10:33:46 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
	free((void*)s1);
	s3[i] = '\0';
	return (s3);
}

