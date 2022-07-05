/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:32:06 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/05 16:32:32 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_next_line(int fd)
{
	int rd = 0;
	char	c;
	if ((rd = read(fd, &c, 1)) == 0)
		return (NULL); // Возвращаем NULL, если файл пустой
	char	*line = malloc(100000); // 1000000 для BigFile1
	char	*word = line;
	*line++ = c;
	while ((rd = read(fd, &c, 1)) > 0 && c != '\n')
		*line++ = c;
	if (c == '\n')
		*line++ = '\n';
	*line = '\0';
	return (word);
}