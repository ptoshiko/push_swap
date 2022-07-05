// read with gnl
// gnl(0) -- standart input
// how to stop ? 
// 

#include <stdio.h>

#include "push_swap.h"

// int	ft_continue(char **char_arr, int len, int *int_arr, t_env *env)
// {
// 	int_arr = make_arr(char_arr);
// 	if (int_arr == 0)
// 	{
// 		clean_char(char_arr, len);
// 		return (0);
// 	}
// 	if (check_arr_sorted(int_arr, len))
// 	{
// 		free(int_arr);
// 		clean_char(char_arr, len);
// 		return (0);
// 	}
// 	make_env(&env, int_arr, len);
// 	sort_arr(&int_arr, char_arr);
// 	if (check_repeat(int_arr, len) == 1)
// 	{
// 		clean_all(int_arr, char_arr, len, env);
// 		return (0);
// 	}
// 	printf("ok");
	
// // 	// sort_sort(env, int_arr, len);
// // 	// clean_all(int_arr, char_arr, len, env);
// 	return (0);
// }

char **read_instructions()
{
	char *line;
	char *str;
	char **arr;
	int i;
	i = 0;

	line = get_next_line(0);
	while(line)
	{
		str = line;
		free(line);
		str = ft_strjoin(ft_strjoin(str, " "), line = get_next_line(0));
	}
	arr = ft_split(str, ' ');
	if (arr == NULL)
		return (0);
	free(str);
	while(arr[i])
	{
		printf("%s", arr[i]);
		i++;
	}
	return(arr);	
}

// char	**parse_parse(int argc, char **argv)
// {
// 	char	**arr;
// 	char	*str;
// 	int		i;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		str = ft_strdup(argv[1]);
// 		i = 2;
// 		while (i < argc)
// 		{
// 			str = ft_strjoin(ft_strjoin(str, " "), argv[i]);
// 			i++;
// 		}
// 		arr = ft_split(str, ' ');
// 		if (arr == NULL)
// 			return (0);
// 	}
// 	free(str);
// 	return (arr);
// }

int	main(int argc, char **argv)
{
	t_env	*env;
	char	**char_arr;
	int		*int_arr;
	int		len;
	char	**instructions;

	int_arr = NULL;
	env = NULL;
	if (argc < 2)
		return (0);
	// if (!(ft_strncmp(argv[1], "", 1)))
	// {
	// 	write(1, "Error\n", 6);
	// 	return (0);
	// }
	char_arr = parse_argv(argc, argv);
	len = count_arr(char_arr);
	if (check_digit(char_arr) == 1)
	{
		clean_char(char_arr, len);
		return (0);
	}
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
	printf("ok\n");
	instructions = read_instructions();
	// line = get_next_line(0);
	// while(line)
	// {

	// }
	// printf("%s\n", line);
	return(0); 
}

	// ft_continue(char_arr, len, int_arr, env);
