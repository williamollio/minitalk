/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:13:31 by wollio            #+#    #+#             */
/*   Updated: 2021/06/29 11:56:09 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, char n, size_t a)
{
	char	*replace;

	replace = (char *)ptr;
	while (a > 0)
	{
		replace[a - 1] = n;
		a--;
	}
	return (replace);
}
