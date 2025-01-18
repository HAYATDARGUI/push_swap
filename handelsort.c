/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handelsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:55:08 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/18 11:29:28 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void handele3(t_node **lst_a)
{
    int nb_1=(*lst_a)->position;
    int nb_2=(*lst_a)->next_node->position;
    int nb_3=(*lst_a)->next_node->next_node->position;
    
    if(nb_2 > nb_1 && nb_1 > nb_3)
    {
        ra(lst_a,0);
        ra(lst_a,0);
    }
    else if(nb_1>nb_2 &&nb_2>nb_3)
    {
        ra(lst_a,0); 
        sa(lst_a,0);
    }
   if(nb_1 > nb_2 && nb_3 > nb_1)
   {
        sa(lst_a,0);
   }
   else if(nb_2 > nb_3 && nb_3 > nb_1)
   {
        rra(lst_a,0);
        sa(lst_a,0);
   }
   else if (nb_1 > nb_3 && nb_3 > nb_2)
   {
        rra(lst_a,0);
        rra(lst_a,0);
   }
}

void handle4(t_node **lst_a,t_node **lst_b)
{
    int a= maxnumber(lst_a);

    int i=0;
    while(i<a && a!=3)
    {
        ra(lst_a,0);
        i++;
    }
    if(a==3)
    {
        rra(lst_a,0);
    }
    pb(lst_a,lst_b,0);

    handele3(lst_a);
    pa(lst_a,lst_b,0);
    ra(lst_a, 0);
}
void handle5(t_node **lst_a,t_node **lst_b)
{
     int a= maxnumber(lst_a);
     int i=0;
    while(i<a && a!=3)
    {
        ra(lst_a,0);
        i++;
    }
    if(a==3)
    {
        rra(lst_a,0);
    }
    pb(lst_a,lst_b,0);
    
    handle4(lst_a,lst_b);
    pa(lst_a,lst_b,0);
    ra(lst_a, 0);
}
