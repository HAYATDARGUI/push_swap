/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handelsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:55:08 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/24 12:59:27 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int already_sorted(t_node *lst_a)
{
    if(!lst_a)
    {
        return 0;
    }
    while (lst_a->next_node)
    {
        if(lst_a->data >lst_a->next_node->data)
        {
            return 0;
        }
        lst_a=lst_a->next_node;
    }
    return 1;
}

void handele3(t_node **lst_a)
{
    int nb_1=(*lst_a)->position;
    int nb_2=(*lst_a)->next_node->position;
    int nb_3=(*lst_a)->next_node->next_node->position;
    
    if(nb_2 > nb_1 && nb_1 > nb_3)
    {
        ra(lst_a,1);
        ra(lst_a,1);
    }
    else if(nb_1>nb_2 &&nb_2>nb_3)
    {
        ra(lst_a,1); 
        sa(lst_a,1);
    }
   if(nb_1 > nb_2 && nb_3 > nb_1)
        sa(lst_a,1);
   else if(nb_2 > nb_3 && nb_3 > nb_1)
   {
        rra(lst_a,1);
        sa(lst_a,1);
   }
   else if (nb_1 > nb_3 && nb_3 > nb_2)
   {
        rra(lst_a,1);
        rra(lst_a,1);
   }
}

int stacksize(t_node *lst_a)
{
    t_node *current;
    int size=0;
    current =lst_a;
    while (current)
    {
        size++;
        current=current->next_node;
    }
    return size;
}
void handle4(t_node **lst_a,t_node **lst_b)
{
    int a= minnumber(lst_a);
    if(a==3)
    {
        rra(lst_a,1);
    }
    else{

        while(a)
        {
            ra(lst_a,1);
            a--;
        }
    }
    pb(lst_a,lst_b,1);
    handele3(lst_a);
    pa(lst_a,lst_b,1);
}

void handle5(t_node **lst_a, t_node **lst_b)
{
    int min = minnumber(lst_a);
    
    if(min==4)
    {
        rra(lst_a,1);
    }
    else
    {
        while(min)
        {
            ra(lst_a,1);
            min--;
        }
    }
    pb(lst_a, lst_b, 1);

    handle4(lst_a, lst_b);
    
    pa(lst_a, lst_b, 1);
}

int deja_vu(t_node *lst_a)
{
    if(!lst_a)
    {
        return 0;
    }
    while (lst_a->next_node)
    {
        if(lst_a->data >lst_a->next_node->data)
        {
            return 0;
        }
        lst_a=lst_a->next_node;
    }
    return 1;
}

void push_to_stack_b(t_node **lst_a, t_node **lst_b)
{
    int size = stacksize(*lst_a);
    int min = 0;
    int max = (int)(0.048 * size + 10);
    
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
        {
            ra(lst_a, 1);
        }
    }
}

void push_b_to_a(t_node **lst_a, t_node **lst_b)
{
    int size;
    int max;
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
        else if( max != 1)
        {
            while (max <= size)
            {
                rrb(lst_b, 1);
                max++;
            }
        }
        pa(lst_a, lst_b, 1);
    }
}

void sort_stack(t_node **lst_a,t_node **lst_b)
{
    int size_of_stack;
    if(!lst_a || !*lst_a)
    {
        return ;
    }
    if(deja_vu(*lst_a))
    {
        return ;
    }
    
    size_of_stack=stacksize(*lst_a);
    
    if(size_of_stack==2)
    {
        sa(lst_a, 0);
    }
    else if(size_of_stack==3)
    {
        handele3(lst_a);
    }
    else if(size_of_stack==4)
    {
        handle4(lst_a,lst_b);
    }
    else if(size_of_stack==5)
    {
        handle5(lst_a,lst_b);
    }
    else
    {
           push_to_stack_b(lst_a,lst_b);
           push_b_to_a(lst_a,lst_b);
    }
}