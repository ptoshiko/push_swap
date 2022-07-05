/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:22:43 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/05 13:47:19 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_env *env)
{
	if (env->list_a->value != env->min)
		return (1);
	else
		return (0);
}

void	make_final(t_env *env)
{
	t_list	*tmp;

	tmp = env->list_a;
	while (tmp->value != env->min && tmp)
	{
		env->ra++;
		tmp = tmp->next;
	}
	env->rra = ft_lstsize(env->list_a) - env->ra;
	if (env->ra < env->rra)
	{
		while (env->ra > 0)
		{
			make_ra(env, 1);
			env->ra--;
		}
	}
	else
	{
		while (env->rra > 0)
		{
			make_rra(env, 1);
			env->rra--;
		}
	}
}

void	sort_sort(t_env *env, int *int_arr, int len)
{
	if (len == 3)
		sort_three(env);
	else if (len == 5)
		sort_five(env, int_arr);
	else
	{
		sort_list(env, int_arr);
		if (check_sorted(env) == 1)
		{
			make_final(env);
		}	
	}
}

int	ft_continue(char **char_arr, int len, int *int_arr, t_env *env)
{
	int_arr = make_arr(char_arr);
	if (int_arr == 0)
	{
		clean_char(char_arr, len);
		return (0);
	}
	if (check_arr_sorted(int_arr, len))
	{
		free(int_arr);
		clean_char(char_arr, len);
		return (0);
	}
	make_env(&env, int_arr, len);
	sort_arr(&int_arr, char_arr);
	if (check_repeat(int_arr, len) == 1)
	{
		clean_all(int_arr, char_arr, len, env);
		return (0);
	}
	sort_sort(env, int_arr, len);
	clean_all(int_arr, char_arr, len, env);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	*env;
	char	**char_arr;
	int		*int_arr;
	int		len;

	int_arr = NULL;
	env = NULL;
	if (argc < 2)
		return (0);
	if (!ft_strncmp(argv[1], "\n", 1)) // not 
	{
		write(1, "Error\n", 6);
		return (0);
	}
	char_arr = parse_argv(argc, argv);
	len = count_arr(char_arr);
	if (check_digit(char_arr) == 1)
	{
		clean_char(char_arr, len);
		return (0);
	}
	ft_continue(char_arr, len, int_arr, env);
}

// check sorted?
//no sotring 
//yes  
//do final sort by rotating 
//find 3: min max med 
// all except that three goes to b
//chaeck if sorted and sort for three sort_three
// ft_scorescore_b_r score_b_rr score_a_r score_a_rr
// make_decision
// proccess
// if we have something in b we count score agai 
