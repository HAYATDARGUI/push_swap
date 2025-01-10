/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:17:13 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/07 17:40:54 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str,int *in_range)
{
	int					sign;
	unsigned long long	res;

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
		str++;
	}
    if(res >= -2147483648 || res <= 2147483647)
    {
            *in_range = 0;
    }
	return (res * sign);
}
int is_douple(int i,int *new_int,int tmp)
{
    int j = 0;
    while(i > 0)
    {
        if(tmp == new_int[j])
        {
            return 1;
        }  
    }
    return 0;
}

int str_int(char ***new_str,int **new_int,int len1)
{
    int *in_range;
    int tmp;
    int i=0;
    
    *in_range =1;
    i=0;
    *new_int=(int*)malloc(sizeof(int)*(len1));
    if(!new_int)
    {
        return NULL;
    }
    while(i < len1)
    {
        tmp=ft_atoi(**new_str,in_range);
        if(!in_range || is_douple(i,*new_int,tmp))
        {
            free(*new_int);
            return 0;
        }
        (*new_int)[i]=tmp;
    }
    free_split(*new_str);
    return 1;
}