/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:50:09 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/27 11:26:49 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				position;
	struct s_node	*next_node;
	struct s_node	*prev_node;
}					t_node;

void				ss(t_node **lst_a, t_node **lst_b, int i);
int					ft_strncmp(char *s1, char *s2, size_t n);
void				rrr(t_node **lst_a, t_node **lst_b, int i);
int					deja_vu(t_node *lst_a);
int					stacksize(t_node *lst_a);
void				push_b_to_a(t_node **lst_a, t_node **lst_b);
void				push_to_stack_b(t_node **lst_a, t_node **lst_b);
int					stacksize(t_node *lst_a);
char				**ft_split(char const *s, char c);
char				**free_split(char **alloc);
int					str_int(char ***new_str, int **new_int, int len1);
int					to_stack(int *new_int, int len, t_node **lst);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
int					count_words(const char *str, char c);
char				*ft_strjoin(char const *s1, char const *s2);
t_node				*ft_lstnew(int content);
void				ft_lstadd_front(t_node **lst, t_node *newn);
t_node				*ft_lstlast(t_node *lst);
void				ft_lstadd_back(t_node **lst, t_node *newlst);
int					parsing(char **arv, t_node **lst);
void				sort_stack(t_node **lst_a, t_node **lst_b);
void				sa(t_node **lst, int i);
void				sb(t_node **lst, int i);
int					minnumber(t_node **lst_a);
int					maxnumber(t_node **lst_a);
void				rb(t_node **lst_b, int i);
void				rr(t_node **lst_b, t_node **lst_a, int i);
void				ra(t_node **lst_a, int i);
void				rra(t_node **lst_a, int i);
void				pb(t_node **lst_a, t_node **lst_b, int i);
void				pa(t_node **lst_a, t_node **lst_b, int i);
void				rrb(t_node **lst_b, int i);
void				reverse_rotate_stack(t_node **lst);
void				free_stack(t_node **lst);
void				help_function2(t_node **lst_a, int nb_1, int nb_2,
						int nb_3);

#endif
