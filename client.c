/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:42:45 by wollio            #+#    #+#             */
/*   Updated: 2021/09/20 11:20:58 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <sys/types.h>

/* Send each characters bit by bit with a bitwise operator */
void	ft_sending(char c, pid_t pid_server)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid_server;
	char	*string;
	int		length_string;
	int		i;

	if (argc == 3)
	{
		i = 0;
		pid_server = ft_atoi(argv[1]);
		string = argv[2];
		length_string = ft_strlen(string);
		while (i < length_string)
		{
			ft_sending(string[i], pid_server);
			i++;
		}
	}
	else
		write(1, "./client pid string\n", 20);
	ft_putstr_fd("---- Data sent to the server ----\n", 1);
	return (0);
}

/** OLD VERSION **

** Reverse a string
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

** Convert integer to binary
char	*int_to_bin(int c)
{
	char	*bin;
	int		i;

	bin = (char *)malloc(9);
	i = 0;
	while(c > 0)
	{
		bin[i] = c % 2 + '0';
		c /= 2;
		i++;
	}
	bin[i] = '0';
	bin[++i] = 0;
	ft_revers(bin);
	return (bin);
}

** Go trough the string and send it to the server as signals
void ft_sending(char *str, pid_t pid)
{
	int i;

	i = 0;
	printf("Byte sent : %s\n", str);
	while(str[i])
	{
		if (str[i] == '0')
			kill(pid, SIGUSR1);
		else if (str[i] == '1')
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
	return;
}
*/