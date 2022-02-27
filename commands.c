/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:26:40 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/02/21 18:26:10 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_sa(t_env *env, int flag)
{
	t_list	*temp;

	if ((env->list_a) == NULL || (env->list_a->next) == NULL)
		return ;
	temp = env->list_a->next;
	env->list_a->next = temp->next;
	temp->next = env->list_a;
	env->list_a = temp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	make_ra(t_env *env, int flag)
{
	t_list	*first;
	t_list	*rotate;
	t_list	*last;

	if (env->list_a == NULL || env->list_a->next == NULL)
		return ;
	rotate = env->list_a;
	first = env->list_a->next;
	last = env->list_a;
	while (last->next != NULL)
		last = last->next;
	rotate->next = NULL;
	last->next = rotate;
	env->list_a = first;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	make_rb(t_env *env, int flag)
{
	t_list	*first;
	t_list	*rotate;
	t_list	*last;

	if (env->list_b == NULL || env->list_b->next == NULL)
		return ;
	rotate = env->list_b;
	first = env->list_b->next;
	last = env->list_b;
	while (last->next != NULL)
		last = last->next;
	rotate->next = NULL;
	last->next = rotate;
	env->list_b = first;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	make_rra(t_env *env, int flag)
{
	t_list	*first;
	t_list	*rotate;
	t_list	*penult;

	if (env->list_a == NULL || env->list_a->next == NULL)
		return ;
	first = env->list_a;
	penult = env->list_a;
	while (penult->next->next != NULL)
		penult = penult->next;
	rotate = penult->next;
	penult->next = NULL;
	rotate->next = first;
	env->list_a = rotate;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	make_rrb(t_env *env, int flag)
{
	t_list	*first;
	t_list	*rotate;
	t_list	*penult;

	if (env->list_b == NULL || env->list_b->next == NULL)
		return ;
	first = env->list_b;
	penult = env->list_b;
	while (penult->next->next != NULL)
		penult = penult->next;
	rotate = penult->next;
	penult->next = NULL;
	rotate->next = first;
	env->list_b = rotate;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

// void	make_pb(t_env *env, int flag)
// {
// 	t_list	*temp;

// 	if (env->list_a)
// 	{
// 		if (env->list_b == NULL)
// 		{
// 			temp = env->list_a;
// 			env->list_a = env->list_a->next;
// 			env->list_b = temp;
// 			temp->next = NULL;
// 		}
// 		else
// 		{
// 			temp = env->list_a;
// 			env->list_a = env->list_a->next;
// 			temp->next = env->list_b;
// 			env->list_b = temp;
// 		}
// 		if (flag == 1)
// 			write(1, "pb\n", 3);
// 	}
// }

// void	make_pa(t_env *env, int flag)
// {
// 	t_list	*temp;

// 	temp = env->list_b;
// 	env->list_b = env->list_b->next;
// 	temp->next = env->list_a;
// 	env->list_a = temp;
// 	if (flag == 1)
// 		write(1, "pa\n", 3);
// }

// void	make_rr(t_env *env)
// {
// 	make_ra(env, 0);
// 	make_rb(env, 0);
// 	write(1, "rr\n", 3);
// }

// void	make_rrr(t_env *env)
// {
// 	make_rra(env, 0);
// 	make_rrb(env, 0);
// 	write(1, "rrr\n", 4);
// }
