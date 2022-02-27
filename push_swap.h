/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:26:08 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/02/21 15:30:19 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>

// type -- best operation type for element
// min -- min operation for element 

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	int				score_rb;
	int				score_rrb;
	int				score_ra;
	int				score_rra;
	int				score_rr;
	int				score_rrr;
	int				flag;
	int				*arr;
	int				type;
	int				min;
}	t_list;

typedef struct s_env
{
	t_list	*list_b;
	t_list	*list_a;
	t_list	*push;
	int		count_a;
	int		count_b;
	int		min;
	int		max;
	int		med;
	int		ra;
	int		rra;
}	t_env;

void	make_env(t_env **env, int *int_arr, int len);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	list_clear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*make_list(int *int_arr, int len);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	sort_three(t_env *env);
void	make_sa(t_env *env, int flag);
void	make_ra(t_env *env, int flag);
void	make_rb(t_env *env, int flag);
void	make_rra(t_env *env, int flag);
void	make_rrb(t_env *env, int flag);
void	make_pb(t_env *env, int flag);
void	make_pa(t_env *env, int flag);
void	make_rr(t_env *env);
void	make_rrr(t_env *env);
void	sort_list(t_env *env, int *arr);
int		count_arr(char **char_arr);
int		check_repeat(int *arr, int len);
int		check_digit(char **arr);
int		*make_arr(char **char_arr);
void	sort_arr(int **int_arr, char **char_arr);
char	**parse_argv(int argc, char **argv);
void	clean_score(t_env *env);
void	clean_char(char **char_arr, int len);
void	clean_all(int *int_arr, char **char_arr, int len, t_env *env);
void	count_score_rb(t_env *env);
void	count_score_rrb(t_env *env);
void	count_score_ra(t_env *env);
void	count_score_rra(t_env *env);
void	count_score_rrr(t_env *env);
void	count_score_rr(t_env *env);
void	sort_con_a(t_env *env);
void	sort_five(t_env *env, int *arr);
void	sort_three(t_env *env);
void	find_best_comb(t_env *env);
void	find_best_elem(t_env *env);
void	make_rr_ra(t_env *env);
void	make_rr_rb(t_env *env);
void	make_rrr_rra(t_env *env);
void	make_rrr_rrb(t_env *env);
void	make_rb_rra(t_env *env);
void	make_rrb_ra(t_env *env);
void	manage_elem(t_env *env);

#endif