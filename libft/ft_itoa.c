/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:16:56 by wollio            #+#    #+#             */
/*   Updated: 2021/07/02 19:03:06 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_revers(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int static	ft_ternary(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		s_n;

	str = malloc(13);
	if (!str)
		return (0);
	i = 0;
	s_n = n;
	if (n == 0)
		str[i] = '0';
	while (n != 0)
	{
		str[i] = ft_ternary(n % 10) + '0';
		n /= 10;
		i++;
	}
	if (s_n < 0)
		str[i] = '-';
	if (s_n < 0 || s_n == 0)
		i++;
	str[i] = '\0';
	ft_revers(str);
	return (str);
}
