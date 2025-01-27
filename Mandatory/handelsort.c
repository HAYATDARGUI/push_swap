/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handelsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:55:08 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/27 11:28:37 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_node *lst_a)
{
	if (!lst_a)
	{
		return (0);
	}
	while (lst_a->next_node)
	{
		if (lst_a->data > lst_a->next_node->data)
		{
			return (0);
		}
		lst_a = lst_a->next_node;
	}
	return (1);
}

void	handele3(t_node **lst_a)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = (*lst_a)->position;
	nb2 = (*lst_a)->next_node->position;
	nb3 = (*lst_a)->next_node->next_node->position;
	if (nb2 > nb1 && nb1 > nb3)
	{
		ra(lst_a, 1);
		ra(lst_a, 1);
	}
	else if (nb1 > nb2 && nb2 > nb3)
	{
		ra(lst_a, 1);
		sa(lst_a, 1);
	}
	else
		help_function2(lst_a, nb1, nb2, nb3);
}

void	handle4(t_node **lst_a, t_node **lst_b)
{
	int	a;

	a = minnumber(lst_a);
	if (a == 3)
	{
		rra(lst_a, 1);
	}
	else
	{
		while (a)
		{
			ra(lst_a, 1);
			a--;
		}
	}
	pb(lst_a, lst_b, 1);
	handele3(lst_a);
	pa(lst_a, lst_b, 1);
}

void	handle5(t_node **lst_a, t_node **lst_b)
{
	int	min;

	min = minnumber(lst_a);
	if (min == 4)
	{
		rra(lst_a, 1);
	}
	else
	{
		while (min)
		{
			ra(lst_a, 1);
			min--;
		}
	}
	pb(lst_a, lst_b, 1);
	handle4(lst_a, lst_b);
	pa(lst_a, lst_b, 1);
}

void	sort_stack(t_node **lst_a, t_node **lst_b)
{
	int	size_of_stack;

	if (!lst_a || !*lst_a)
		return ;
	if (deja_vu(*lst_a))
		return ;
	size_of_stack = stacksize(*lst_a);
	if (size_of_stack == 2)
		sa(lst_a, 0);
	else if (size_of_stack == 3)
		handele3(lst_a);
	else if (size_of_stack == 4)
		handle4(lst_a, lst_b);
	else if (size_of_stack == 5)
		handle5(lst_a, lst_b);
	else
	{
		push_to_stack_b(lst_a, lst_b);
		push_b_to_a(lst_a, lst_b);
	}
}
