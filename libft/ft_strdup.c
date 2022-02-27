/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:26:29 by ptoshiko          #+#    #+#             */
/*   Updated: 2021/11/08 21:52:58 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (s2 == 0)
		return (0);
	while (i < ft_strlen(s1))
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
