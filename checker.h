/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:57:16 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/07 14:40:58 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"

# define BUFFER_SIZE 10000

char	**read_commands(void);
char	*get_next_line(int fd);
int		stack_sorted(t_env *env);
void	clean_commands(char **arr);
#endif