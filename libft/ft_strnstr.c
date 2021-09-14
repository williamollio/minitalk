/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:45:54 by wollio            #+#    #+#             */
/*   Updated: 2021/07/14 17:41:38 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack && len--)
	{
		i = 0;
		l = len + 1;
		while (haystack[i] && needle[i] && haystack[i] == needle[i] && len--)
			i++;
		if (i == ft_strlen(needle))
			return (((char *)haystack));
		haystack++;
	}
	return (NULL);
}

// i l l i a m
// i l
