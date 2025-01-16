/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handelsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:55:08 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/16 17:42:06 by hdargui          ###   ########.fr       */
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
#include <stdio.h>

int main()
{
    // Create a sample linked list for lst_a with three nodes
    t_node *head_a = (t_node *)malloc(sizeof(t_node));
    t_node *second_a = (t_node *)malloc(sizeof(t_node));
    t_node *third_a = (t_node *)malloc(sizeof(t_node));

    head_a->position = 2;
    head_a->next_node = second_a;
    head_a->prev_node = NULL;

    second_a->position = 3;
    second_a->next_node = third_a;
    second_a->prev_node = head_a;

    third_a->position = 1;
    third_a->next_node = NULL;
    third_a->prev_node = second_a;

    // Initialize lst_b as an empty list
    t_node *head_b = NULL;

    // Call the handle4 function
    handle4(&head_a, &head_b);

    // Print the result to verify the list is sorted and the maximum element is handled correctly
    t_node *current = head_a;
    printf("List A: ");
    while (current != NULL)
    {
        printf("%d ", current->position);
        current = current->next_node;
    }
    printf("\n");

    current = head_b;
    printf("List B: ");
    while (current != NULL)
    {
        printf("%d ", current->position);
        current = current->next_node;
    }
    printf("\n");

    // Free the allocated memory
    free(third_a);
    free(second_a);
    free(head_a);

    return 0;
}