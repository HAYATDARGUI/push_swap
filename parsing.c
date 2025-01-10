/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:55:31 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/07 17:41:40 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_valide(char **arv)
{
    int i=0;
    while(arv[i])
    {
        if(count_words(arv[i],' ')==0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

char  *join_to_string(char **arv)
{
    int i=1;
    char *string;
    string =ft_strdup("");
  
    while(arv[i])
    {
        string=ft_strjoin(string,arv[i]);
        if(!string)
        {
            return NULL;
        }
        if(arv[i+1])
        {
            string=ft_strjoin(string," "); 
            if(!string)
            {
                return NULL;
            }
        }
        i++;
    }
    return string;
}

char *validate_join(char **join, char **arv,int *len)
{
	int i=0;
	*join=join_to_string(arv);
	if(!join)
	{
		return NULL;
	}
	while(*join)
	{
		if(!(*join[i]==' ' || *join[i]=='-'||*join[i] == '+' ||(*join[i]>='0'&& *join[i]<='9')))
		{
      free(*join);
      return 0;
		}
    join++;
	}
  *len=(count_words(*join,' '));
  return 0;
}

int split_string(char *join,char ***new_str)
{
  *new_str=ft_split(join,' ');
  if(!new_str)
  {
    return 0;
  }
  free(join);
  return 1;
}

int parsing(char **arv, t_node **lst)
{
  char *join;
  char **new_str;
  int  *new_int;
  int len;
  
  len=0;
  join=0;
  if(!is_valide(arv))
  {
    return 0;
  }
  if(!validate_join(&join,arv,&len))
  {
    return 0;
  }
  if(!split_string(join,&new_str))
  {
    return 0;
  }
  if(!str_int(&new_str,&new_int,len))
  {
    return 0;
  }
  if(!to_stack(new_int,len,lst))
  {
    return 0;
  }
  return 1;
}
