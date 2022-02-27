/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:23:51 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/02/21 18:47:00 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_pb(t_env *env, int flag)
{
	t_list	*temp;

	if (env->list_a)
	{
		if (env->list_b == NULL)
		{
			temp = env->list_a;
			env->list_a = env->list_a->next;
			env->list_b = temp;
			temp->next = NULL;
		}
		else
		{
			temp = env->list_a;
			env->list_a = env->list_a->next;
			temp->next = env->list_b;
			env->list_b = temp;
		}
		if (flag == 1)
			write(1, "pb\n", 3);
	}
}

void	make_pa(t_env *env, int flag)
{
	t_list	*temp;

	temp = env->list_b;
	env->list_b = env->list_b->next;
	temp->next = env->list_a;
	env->list_a = temp;
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	make_rr(t_env *env)
{
	make_ra(env, 0);
	make_rb(env, 0);
	write(1, "rr\n", 3);
}

void	make_rrr(t_env *env)
{
	make_rra(env, 0);
	make_rrb(env, 0);
	write(1, "rrr\n", 4);
}
