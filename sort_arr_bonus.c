/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:02:16 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/02/21 15:02:33 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_arr(char **char_arr)
{
	int	i;

	i = 0;
	while (char_arr[i] != NULL)
		i++;
	return (i);
}

void	sort_arr(int **int_arr, char **char_arr)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	while (i < count_arr(char_arr))
	{
		j = 0;
		while (j < count_arr(char_arr) - 1)
		{
			if ((*int_arr)[j] > (*int_arr)[j + 1])
			{
				b = (*int_arr)[j];
				(*int_arr)[j] = (*int_arr)[j + 1];
				(*int_arr)[j + 1] = b;
			}
			j++;
		}
		i++;
	}
}

int	check_arr_sorted(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] >= arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
