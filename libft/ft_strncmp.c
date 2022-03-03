/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angelinamazurova <angelinamazurova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:17:02 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/03/03 13:12:12 by angelinamaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	int				i;

	arr1 = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (arr1[i] != arr2[i])
			return (arr1[i] - arr2[i]);
		if (arr1[i] == '\0' || arr2[i] == '\0')
			return (0);
		i++;
		n--;
	}
	return (0);
}
