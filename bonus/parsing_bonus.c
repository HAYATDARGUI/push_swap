/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:55:31 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/27 15:32:41 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/push_swap.h"

static int	is_valide(char **arv)
{
	int	i;

	i = 0;
	while (arv[i])
	{
		if (count_words(arv[i], ' ') == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*join_to_string(char **arv)
{
	int		i;
	char	*string;

	i = 0;
	string = ft_strdup("");
	while (arv[i])
	{
		string = ft_strjoin(string, arv[i]);
		if (!string)
		{
			return (NULL);
		}
		if (arv[i + 1])
		{
			string = ft_strjoin(string, " ");
			if (!string)
			{
				return (NULL);
			}
		}
		i++;
	}
	return (string);
}

char	*validate_join(char **join, char **arv, int *len)
{
	int	i;

	i = 0;
	*join = join_to_string(arv);
	if (!*join)
		return (NULL);
	while ((*join)[i])
	{
		if (!((*join)[i] == ' ' || (*join)[i] == '-' || (*join)[i] == '+'
				|| ((*join)[i] >= '0' && (*join)[i] <= '9')))
			return (free(*join), *join = NULL, NULL);
		if (((*join)[i] == '+' || (*join)[i] == '-') && (i == 0 || (*join)[i
				- 1] == ' '))
		{
			if (!((*join)[i + 1] >= '0' && (*join)[i + 1] <= '9'))
				return (free(*join), *join = NULL, NULL);
		}
		else if (((*join)[i] == '+' || (*join)[i] == '-') && i > 0)
			return (free(*join), *join = NULL, NULL);
		i++;
	}
	*len = (count_words(*join, ' '));
	return (*join);
}

int	split_string(char *join, char ***new_str)
{
	*new_str = ft_split(join, ' ');
	if (!*new_str)
	{
		return (0);
	}
	free(join);
	return (1);
}

int	parsing(char **arv, t_node **lst)
{
	char	*join;
	char	**new_str;
	int		*new_int;
	int		len;

	len = 0;
	join = 0;
	if (!is_valide(arv))
		return (0);
	if (!validate_join(&join, arv, &len))
		return (0);
	if (!split_string(join, &new_str))
		return (0);
	if (!str_int(&new_str, &new_int, len))
		return (0);
	if (!to_stack(new_int, len, lst))
		return (0);
	return (1);
}
