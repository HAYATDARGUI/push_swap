/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:00:09 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/24 15:25:55 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_stack(t_node **lst)
{
	t_node	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next_node;
		free(tmp);
	}
	lst = NULL;
}

int	main(int argc, char **argv)
{
    t_node	*lst_a;
    t_node	*lst_b;

    (void)argc;
    lst_a = NULL;
    lst_b = NULL;
	
    if (!parsing(argv + 1, &lst_a))
    {
        error();
    }
    else
    {
        sort_stack(&lst_a, &lst_b);
    }
    free_stack(&lst_a);
	free_stack(&lst_b);
    return (0);
}