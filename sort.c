/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:25:40 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/07 15:06:53 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_con_a(t_env *env)
{
	t_list	*temp;
	int		nb[3];
	int		i;

	i = 0;
	temp = env->list_a;
	while (temp != 0)
	{
		nb[i] = temp->value;
		temp = temp->next;
		i++;
	}
	if (nb[0] > nb[1] && nb[1] > nb[2] && nb[0] > nb[2])
		make_sa(env, 1);
	else if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] < nb[2])
	{
		make_rra(env, 1);
		make_sa(env, 1);
	}
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] < nb[2])
		make_sa(env, 1);
	else if (nb[0] < nb[1] && nb[1] < nb[2] && nb[0] < nb[2])
		make_rra(env, 1);
}

void	count_score(t_env *env)
{
	count_score_rb(env);
	count_score_rrb(env);
	count_score_ra(env);
	count_score_rra(env);
	count_score_rrr(env);
	count_score_rr(env);
}

void	find_mmm(t_env *env, int *arr)
{
	env->min = arr[0];
	env->max = arr[(ft_lstsize(env->list_a)) - 1];
	env->med = arr[(ft_lstsize(env->list_a)) / 2];
}

void	sort_list(t_env *env, int *arr)
{
	find_mmm(env, arr);
	while (env->count_a > 3)
	{
		if (env->list_a->value != env->min && env->list_a->value != env->max \
		&& env->list_a->value != env->med)
		{
			env->count_b++;
			env->count_a--;
			make_pb(env, 1);
		}
		else
			make_ra(env, 1);
	}
	sort_con_a(env);
	while (env->list_b != NULL)
	{
		clean_score(env);
		count_score(env);
		find_best_comb(env);
		find_best_elem(env);
		manage_elem(env);
	}
}
