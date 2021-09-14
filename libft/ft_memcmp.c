/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:35:40 by wollio            #+#    #+#             */
/*   Updated: 2021/06/28 19:01:12 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				result;
	unsigned char	*sa;
	unsigned char	*sb;

	sa = (unsigned char *)s1;
	sb = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		result = sa[i] - sb[i];
		if (result != 0)
			return (result);
		i++;
	}
	return (0);
}
