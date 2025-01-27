/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:39:13 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/27 18:53:20 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	moves(t_node **lst_a, t_node **lst_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(lst_a, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(lst_b, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(lst_a, lst_a, 0);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(lst_a, lst_b, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(lst_a, lst_b, 0);
	else if (!ft_strncmp(line, "ra\n", 4))
		ra(lst_a, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(lst_b, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(lst_a, lst_b, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(lst_a, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(lst_b, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(lst_a, lst_b, 0);
	else
		error();
}

void	ok_or_ko(t_node *lst_a, t_node *lst_b)
{
	if (deja_vu(lst_a) && !lst_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_node	*lst_a;
	t_node	*lst_b;
	char	*line;

	lst_a = NULL;
	lst_b = NULL;
	line = NULL;
	if (argc < 2)
		return (0);
	if (!parsing(argv + 1, &lst_a))
		error();
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		moves(&lst_a, &lst_b, line);
		free(line);
		line = NULL;
	}
	ok_or_ko(lst_a, lst_b);
	free_stack(&lst_a);
	return (0);
}
