/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:37:29 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/02/20 18:02:42 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_five(t_env *env, int *arr)
{
	int		min;
	int		min_next;

	min = arr[0];
	min_next = arr[1];
	while (env->count_a > 3)
	{
		if (env->list_a->value == min || env->list_a->value == min_next)
		{
			make_pb(env, 1);
			env->count_a--;
		}
		else
			make_ra(env, 1);
	}
	sort_three(env);
	if (env->list_b->value < env->list_b->next->value)
		make_rb(env, 1);
	make_pa(env, 1);
	make_pa(env, 1);
}
