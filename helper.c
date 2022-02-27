/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:26:38 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/02/21 15:30:51 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*make_list(int *int_arr, int len)
{
	t_list	*list;
	t_list	*elem;
	int		j;

	j = 0;
	list = ft_lstnew(int_arr[j]);
	list->flag = 0;
	j++;
	while (j < len)
	{
		elem = ft_lstnew(int_arr[j]);
		elem->flag = 0;
		ft_lstadd_back(&list, elem);
		j++;
	}
	return (list);
}

void	make_env(t_env **env, int *int_arr, int len)
{
	*env = (t_env *)malloc(sizeof(t_env));
	(*env)->list_a = make_list(int_arr, len);
	(*env)->list_b = NULL;
	(*env)->push = NULL;
	(*env)->count_a = len;
	(*env)->count_b = 0;
	(*env)->min = 0;
	(*env)->max = 0;
	(*env)->med = 0;
	(*env)->ra = 0;
	(*env)->rra = 0;
}

void	clean_score(t_env *env)
{
	t_list	*tmp;

	tmp = env->list_b;
	while (tmp)
	{
		tmp->score_ra = 0;
		tmp->score_rb = 0;
		tmp->score_rr = 0;
		tmp->score_rra = 0;
		tmp->score_rrb = 0;
		tmp->score_rrr = 0;
		tmp = tmp->next;
	}
}
