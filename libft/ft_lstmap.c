/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:05:09 by wollio            #+#    #+#             */
/*   Updated: 2021/07/05 19:30:52 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		l;
	t_list	*new;
	t_list	*start;
	t_list	*element;

	l = ft_lstsize(lst);
	start = lst;
	new = (t_list *)malloc(sizeof(t_list) * l);
	if (!new)
		return ((t_list *) NULL);
	new = NULL;
	while (lst != NULL)
	{
		element = ft_lstnew((t_list *)f((t_list *)lst->content));
		if (!element)
			ft_lstclear(&start, del);
		else
			ft_lstadd_back(&new, element);
		lst = lst->next;
	}
	return (new);
}
