/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:35:02 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/02/21 12:35:22 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_score_rrr(t_env *env)
{
	t_list	*tmp;
	int		rrb;
	int		rra;

	tmp = env->list_b;
	while (tmp)
	{
		rrb = tmp->score_rrb;
		rra = tmp->score_rra;
		while (rra > 0 && rrb > 0)
		{
			rra--;
			rrb--;
			tmp->score_rrr++;
		}
		tmp = tmp->next;
	}
}

void	count_score_rr(t_env *env)
{
	t_list	*tmp;
	int		ra;
	int		rb;

	tmp = env->list_b;
	while (tmp)
	{
		ra = tmp->score_ra;
		rb = tmp->score_rb;
		while (ra > 0 && rb > 0)
		{
			ra--;
			rb--;
			tmp->score_rr++;
		}
		tmp = tmp->next;
	}
}
