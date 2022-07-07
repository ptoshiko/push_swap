/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:41:49 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/07 15:06:10 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	continue_execute(char *commands, t_env *env)
{
	if (!ft_strncmp(commands, "sa", 2))
		make_sa(env, 0);
	else if (!ft_strncmp(commands, "pa", 2))
		make_pa(env, 0);
	else if (!ft_strncmp(commands, "pb", 2))
		make_pb(env, 0);
	else if (!ft_strncmp(commands, "ra", 2))
		make_ra(env, 0);
	else if (!ft_strncmp(commands, "rb", 2))
		make_rb(env, 0);
	else if (!ft_strncmp(commands, "rr", 2))
		make_rr(env, 0);
	else
	{
		write(1, "Error\n", 6);
		return ;
	}
}

void	execute_commands(char **commands, t_env *env)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		if (!ft_strncmp(commands[i], "rra", 3))
			make_rra(env, 0);
		else if (!ft_strncmp(commands[i], "rrb", 3))
			make_rrb(env, 0);
		else if (!ft_strncmp(commands[i], "rrr", 3))
			make_rrr(env, 0);
		else
			continue_execute(commands[i], env);
		i++;
	}
}

void	do_commands(t_env *env)
{
	char	**commands;

	commands = read_commands();
	if (*commands != NULL)
		execute_commands(commands, env);
	if (!stack_sorted(env) && env->list_b == NULL)
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	clean_commands(commands);
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
	do_commands(env);
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
	if (!(ft_strncmp(argv[1], "", 1)))
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
