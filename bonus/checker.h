/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:57:51 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/27 15:22:46 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../Mandatory/push_swap.h"

void	free_stack(t_node **lst);
char	*get_next_line(int fd);
int		main(int argc, char **argv);

#endif
