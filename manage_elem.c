/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:57:55 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/02/21 14:46:02 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	make_rr_ra_rb(t_env *env)
{
	while (env->push->score_rr > 0)
	{
		make_rr(env);
		env->push->score_rr--;
		env->push->score_ra--;
		env->push->score_rb--;
	}
	while (env->push->score_ra > 0)
	{
		make_ra(env, 1);
		env->push->score_ra--;
	}
	while (env->push->score_rb > 0)
	{
		make_rb(env, 1);
		env->push->score_rb--;
	}
}

void	make_rrr_rra_rrb(t_env *env)
{
	while (env->push->score_rrr > 0)
	{
		make_rrr(env);
		env->push->score_rrr--;
		env->push->score_rra--;
		env->push->score_rrb--;
	}
	while (env->push->score_rra > 0)
	{
		make_rra(env, 1);
		env->push->score_rra--;
	}
	while (env->push->score_rrb > 0)
	{
		make_rrb(env, 1);
		env->push->score_rrb--;
	}
}

void	make_rb_rra(t_env *env)
{
	while (env->push->score_rb > 0)
	{
		make_rb(env, 1);
		env->push->score_rb--;
	}
	while (env->push->score_rra > 0)
	{
		make_rra(env, 1);
		env->push->score_rra--;
	}
}

void	make_rrb_ra(t_env *env)
{
	while (env->push->score_ra > 0)
	{
		make_ra(env, 1);
		env->push->score_ra--;
	}
	while (env->push->score_rrb > 0)
	{
		make_rrb(env, 1);
		env->push->score_rrb--;
	}
}

void	manage_elem(t_env *env)
{
	if (env->push->type == 0)
	{
		make_rr_ra_rb(env);
		make_pa(env, 1);
	}		
	else if (env->push->type == 1)
	{
		make_rrr_rra_rrb(env);
		make_pa(env, 1);
	}
	else if (env->push->type == 2)
	{
		make_rb_rra(env);
		make_pa(env, 1);
	}
	else if (env->push->type == 3)
	{
		make_rrb_ra(env);
		make_pa(env, 1);
	}
}
