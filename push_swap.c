/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:00:09 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/19 17:28:13 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// int already_sorted(t_node *lst_a)
// {
//     if(!lst_a)
//     {
//         return NULL;
//     }
//     while (lst_a->next_node)
//     {
//         if(lst_a->data >lst_a->next_node->data)
//         {
//             return 0;
//         }
//         lst_a=lst_a->next_node;
//     }
//     return 1;
// }
// int stacksize(t_node *lst_a)
// {
//     t_node *current;
//     int size=0;
//     current =lst_a;
//     while (current)
//     {
//         size++;
//         current=current->next_node;
//     }
//     return size;
// }
// void sort_stack(t_node **lst_a,t_node **lst_b)
// {
//     int size_of_stack;
//     if(!lst_a)
//     {
//         return ;
//     }
//     if(already_sorted(*lst_a))
//     {
//         return ;
//     }
//     size_of_stack=stacksize(*lst_a);
//     if(size_of_stack==2)
//     {
//         sa(lst_a, 0);
//     }
//     if(size_of_stack==3)
//     {
//         handele3(lst_a, 0);
//     }
    
// }