/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:22 by wollio            #+#    #+#             */
/*   Updated: 2021/09/14 20:01:44 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <sys/types.h>

static	t_server server;

void	ft_handler0()
{
	server.flag = 0;
	server.bit--;
}

void	ft_handler1()
{
	server.flag = 1;
	server.bit--;
}
int	main()
{
	pid_t	pid;
	char	c;
	server.bit = 8;
	server.flag = 2;

	c = 0;
	pid = getpid();

	printf("PID of the server : %d\n", pid);
	signal(SIGUSR1, ft_handler0);
	signal(SIGUSR2, ft_handler1);

	ft_putstr_fd("String received by the server : ", 1);
	while(1)
	{
		while(server.bit != 0)
		{
			if (server.flag == 0)
			{
				c += (0 << server.bit);
			}
			if (server.flag == 1)
			{
				c += (1 << server.bit);
			}
		}
		ft_putchar_fd(c, 1);
		server.bit = 8;
		c = 0;
		pause();
	}

	return 0;
}
