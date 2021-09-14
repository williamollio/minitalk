/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:13:04 by wollio            #+#    #+#             */
/*   Updated: 2021/07/19 19:42:57 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcheck(char const s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strcpy(char *s2, char *s1, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start <= end)
	{
		s2[i] = s1[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	start;
	size_t	end;
	char	*s2;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] && ft_strcheck((char const)s1[i], set) == 1)
		i++;
	start = i;
	if (start == ft_strlen(s1))
		return ("");
	i = ft_strlen(s1) - 1;
	if (i == (-1))
		return ("");
	while (s1[i] && ft_strcheck((char const)s1[i], set) == 1)
		i--;
	end = i;
	s2 = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!s2)
		return (0);
	return (ft_strcpy(s2, (char *)s1, start, end));
}
