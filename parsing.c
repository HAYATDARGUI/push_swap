/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:55:31 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/19 16:54:48 by hdargui          ###   ########.fr       */
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
    int i=0;
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
	if(!*join)
	{
		return NULL;
	}
	while((*join)[i])
	{
		if(!((*join)[i]==' ' || (*join)[i]=='-'||(*join)[i] == '+' ||((*join)[i]>='0'&& (*join)[i]<='9')))
		{
            free(*join);
            *join=NULL;
            return NULL;
		}
        i++;
	}
  *len=(count_words(*join,' '));
  return *join;
}
#include <stdio.h>

int split_string(char *join,char ***new_str)
{
  *new_str=ft_split(join,' ');
  if(!*new_str)
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
    if (!is_valide(arv))
        return 0;
    if (!validate_join(&join, arv, &len))
        return 0;
    if (!split_string(join, &new_str))
        return 0;
    if (!str_int(&new_str, &new_int, len))
        return 0;
    if (!to_stack(new_int, len, lst))
        return 0;
    return 1;
}

////////
void sort_stack(t_node **a, t_node **b) {
    // Sorting algorithm (Push-Swap logic)
    while (*a) {
        pb(a, b,0);
        ra(a,0);
    }
    while (*b) {
        pa(a, b,0);
    }
}
void print_stack(t_node *lst) {
    while (lst) {
        printf("%d -> ", lst->data);
        lst = lst->next_node;
    }
    printf("\n");
}

int main(int argc, char **argv) {
    t_node *a = NULL;
    t_node *b = NULL;
    int total_nums;

    if (argc < 2) {
        printf("Usage: ./program arg1 arg2 ...\n");
        return 1;
    }

    // Parse arguments and fill stack `a`
    if (!parsing(argv + 1, &a)) {
        printf("Error in parsing arguments.\n");
        return 1;
    }

    total_nums = argc - 1;

    // Print the initial stack
    printf("Initial stack a: ");
    print_stack(a);

    // Sort the stack using stack b as auxiliary
    sort_stack(&a, &b);

    // Print the sorted stack
    printf("Sorted stack a: ");
    print_stack(a);

    return 0;
}