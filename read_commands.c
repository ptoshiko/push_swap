/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:06:34 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/07 14:07:34 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**read_commands(void)
{
	char	*line;
	char	*str;
	char	**arr;
	int		i;

	i = 0;
	line = get_next_line(0);
	str = ft_strdup(line);
	while (line)
	{
		free(line);
		line = get_next_line(0);
		if (line == NULL)
			break ;
		str = ft_strjoin(ft_strjoin(str, " "), line);
	}
	arr = ft_split(str, ' ');
	if (arr == NULL)
		return (0);
	free(str);
	return (arr);
}
