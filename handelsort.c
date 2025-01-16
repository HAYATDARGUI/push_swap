/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handelsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:55:08 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/16 17:53:04 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void handele3(t_node **lst_a)
{
    // int nb_1=(*lst_a)->position;
    // int nb_2=(*lst_a)->next_node->position;
    // int nb_3=(*lst_a)->next_node->next_node->position;
    if((*lst_a)->next_node->position>(*lst_a)->position&&(*lst_a)->position>(*lst_a)->next_node->next_node->position)
    {
        ra(lst_a,0);
        ra(lst_a,0);
    }
    else if((*lst_a)->position>(*lst_a)->next_node->position &&(*lst_a)->next_node->position>(*lst_a)->next_node->next_node->position)
    {
        ra(lst_a,0); 
        sa(lst_a,0);
    }
   if((*lst_a)->position>(*lst_a)->next_node->position&&(*lst_a)->next_node->next_node->position>(*lst_a)->position)
   {
        sa(lst_a,0);
   }
   else if((*lst_a)->next_node->position>(*lst_a)->next_node->next_node->position&&(*lst_a)->next_node->next_node->position>(*lst_a)->position)
   {
        rra(lst_a,0);
        sa(lst_a,0);
   }
   if((*lst_a)->position>(*lst_a)->next_node->next_node->position && (*lst_a)->next_node->next_node->position> (*lst_a)->next_node->position)
   {
        rra(lst_a,0);
   }
}
void handle4(t_node **lst_a,t_node **lst_b)
{
    int a= maxnumber(lst_a);
    t_node *current=*lst_a;
    while(current!=NULL)
    {
        if(current->position==a)
        {
            pb(lst_a,lst_b,0);
        }
        current=current->next_node;
    }
    handele3(lst_a);
    pa(lst_a,lst_b,0);
    ra(lst_a, 0);
}
void handle5(t_node **lst_a,t_node **lst_b)
{
     int a= maxnumber(lst_a);
    t_node *current=*lst_a;
    while(current!=NULL)
    {
        if(current->position==a)
        {
            pb(lst_a,lst_b,0);
        }
        current=current->next_node;
    }
    handle4(lst_a,lst_b);
    pa(lst_a,lst_b,0);
    ra(lst_a, 0);
}
int main() {
    // Sample data for list A and B
    t_node *lst_a = NULL;
    t_node *lst_b = NULL;

    // Manually adding nodes to lst_a (for example purposes)
    t_node *new_node = malloc(sizeof(t_node));
    new_node->data = 3;
    new_node->position = 1;
    new_node->next_node = lst_a;
    lst_a = new_node;

    new_node = malloc(sizeof(t_node));
    new_node->data = 5;
    new_node->position = 2;
    new_node->next_node = lst_a;
    lst_a = new_node;

    new_node = malloc(sizeof(t_node));
    new_node->data = 2;
    new_node->position = 3;
    new_node->next_node = lst_a;
    lst_a = new_node;

    // Call handle4 function
    handle4(&lst_a, &lst_b);

    // Clean up (free allocated memory)
    t_node *temp;
    while (lst_a != NULL) {
        temp = lst_a;
        lst_a = lst_a->next_node;
        free(temp);
    }
    while (lst_b != NULL) {
        temp = lst_b;
        lst_b = lst_b->next_node;
        free(temp);
    }
    return 0;
}