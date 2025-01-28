/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:17:13 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/28 11:36:56 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if ((res * sign) > (long)2147483647 || (res * sign) < (long)-2147483648)
			error();
		str++;
	}
	return ((long)(res * sign));
}

int	is_douple(int i, int *new_int, int tmp)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (tmp == new_int[j])
		{
			return (1);
		}
		j++;
	}
	return (0);
}

int	str_int(char ***new_str, int **new_int, int len1)
{
	int	tmp;
	int	i;

	i = 0;
	*new_int = (int *)malloc(sizeof(int) * (len1));
	if (!*new_int)
	{
		free_split(*new_str);
		return (0);
	}
	while (i < len1)
	{
		tmp = ft_atoi((*new_str)[i]);
		if (is_douple(i, *new_int, tmp))
			return (free(*new_int), free_split(*new_str), 0);
		(*new_int)[i] = tmp;
		i++;
	}
	free_split(*new_str);
	return (1);
}
