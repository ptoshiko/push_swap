/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:22:58 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/23 15:10:24 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_sum(t_env *env)
{	
	t_list	*tmp;

	tmp = env->list_b;
	while (tmp)
	{
		tmp->arr[0] = tmp->score_ra + tmp->score_rb - tmp->score_rr;
		tmp->arr[1] = tmp->score_rra + tmp->score_rrb - tmp->score_rrr;
		tmp->arr[2] = tmp->score_rb + tmp->score_rra;
		tmp->arr[3] = tmp->score_rrb + tmp->score_ra;
		tmp = tmp->next;
	}
}

void	find_best_comb(t_env *env)
{
	t_list	*tmp;
	int		n;
	int		i;

	make_sum(env);
	tmp = env->list_b;
	while (tmp)
	{
		i = 1;
		n = 4;
		tmp->min = tmp->arr[0];
		tmp->type = 0;
		while (i < n)
		{
			if (tmp->min > tmp->arr[i])
			{
				tmp->min = tmp->arr[i];
				tmp->type = i;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	find_best_elem(t_env *env)
{
	t_list	*tmp;
	int		best;

	tmp = env->list_b;
	best = tmp->min;
	while (tmp)
	{
		if (best >= tmp->min)
		{
			best = tmp->min;
			env->push = tmp;
		}
		tmp = tmp->next;
	}
}
