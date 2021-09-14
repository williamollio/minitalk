/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:47:47 by wollio            #+#    #+#             */
/*   Updated: 2021/07/19 19:42:35 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	length;

	length = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (length > 0)
	{
		if (s[length] == c)
			return ((char *)&s[length]);
		length--;
	}
	if (s[length] == (char)c)
		return ((char *)&s[length]);
	return (NULL);
}
