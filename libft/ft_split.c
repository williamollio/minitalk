/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:16:37 by wollio            #+#    #+#             */
/*   Updated: 2021/07/19 19:40:30 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	row;

	i = 0;
	row = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			row++;
		i++;
	}
	if (s[i - 1] == c)
		row--;
	return (row);
}

char	**ft_snake(char const *s, char c, size_t count, char **mat)
{
	size_t	i;
	size_t	tail;
	size_t	head;

	i = 0;
	head = 0;
	tail = 0;
	while (i < count)
	{
		while (s[head] && s[head] == c)
			head++;
		tail = head;
		while (s[tail] && s[tail] != c)
			tail++;
		if (s[head] == '\0')
			break ;
		mat[i] = (char *)malloc(sizeof(char) * (tail - head + 1));
		ft_memcpy(mat[i], &((char *)s)[head], (tail - head));
		mat[i][tail - head] = '\0';
		i++;
		head = tail;
	}
	mat[i] = NULL;
	return (mat);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**mat;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	mat = (char **)malloc((sizeof(char *) * count) + 1);
	if (!mat)
		return (NULL);
	return (ft_snake(s, c, count, mat));
}
