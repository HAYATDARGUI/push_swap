/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:17:13 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/19 16:51:28 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str,int *in_range)
{
	int					sign;
	unsigned long long	res;

	sign = 1;
	res = 0;
    *in_range=1;
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
        
        if ((res > 2147483647))
        {
            *in_range = 0;
            break;
        }
        str++;
    }
    
	return (int)(res * sign);
}
int is_douple(int i,int *new_int,int tmp)
{
    int j = 0;
    while(j<i)
    {
        if(tmp == new_int[j])
        {
            return 1;
        } 
        j++;
    }
    return 0;
}

int str_int(char ***new_str,int **new_int,int len1)
{
    int in_range;
    int tmp;
    int i=0;
    
    in_range =1;
    i=0;
    *new_int=(int*)malloc(sizeof(int)*(len1));
    if(!*new_int)
    {
        return 0;
    }
    while(i < len1)
    {
        tmp=ft_atoi((*new_str)[i],&in_range);
        if(!in_range || is_douple(i,*new_int,tmp))
        {
            free(*new_int);
            free_split(*new_str);
            return 0;
        }
        (*new_int)[i]=tmp;
        i++;
    }
    free_split(*new_str);
    return 1;
}