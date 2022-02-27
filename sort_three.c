/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:14:59 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/02/21 15:43:25 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_arr_three(t_env *env, int *nb)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = env->list_a;
	while (temp != 0)
	{
		nb[i] = temp->value;
		temp = temp->next;
		i++;
	}
	return (nb);
}

void	sort_three(t_env *env)
{
	int		nb[3];

	make_arr_three(env, nb);
	if (nb[0] > nb[1] && nb[1] > nb[2] && nb[0] > nb[2])
	{
		make_sa(env, 1);
		make_rra(env, 1);
	}
	else if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] < nb[2])
		make_sa(env, 1);
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] < nb[2])
	{
		make_sa(env, 1);
		make_ra(env, 1);
	}
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] > nb[2])
		make_rra(env, 1);
	else if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] > nb[2])
		make_ra(env, 1);
	else
		return ;
}
