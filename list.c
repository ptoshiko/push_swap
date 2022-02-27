/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:35:59 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/02/27 16:26:33 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->value = content;
	node->next = 0;
	node->arr = (int *)malloc(4 * sizeof(int));
	return (node);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*lst = new;
}

void	list_clear(t_list **lst)
{
	t_list	*ptr;

	ptr = *lst;
	while (ptr != NULL )
	{
		*lst = (*lst)->next;
		free(ptr->arr);
		free(ptr);
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*ptr;

// 	while (*lst)
// 	{
// 		(del)((*lst)->value);
// 		ptr = *lst;
// 		*lst = (*lst)->next;
// 		free(ptr);
// 	}
// }

// t_list	*make_list(int *int_arr, int len)
// {
// 	t_list	*list;
// 	t_list	*elem;
// 	int		j;

// 	j = 0;
// 	list = ft_lstnew(int_arr[j]);
// 	j++;
// 	while (j < len)
// 	{
// 		elem = ft_lstnew(int_arr[j]);
// 		ft_lstadd_back(&list, elem);
// 		j++;
// 	}
// 	return (list);
// }
