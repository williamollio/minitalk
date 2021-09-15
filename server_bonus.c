/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:22 by wollio            #+#    #+#             */
/*   Updated: 2021/09/15 19:53:23 by wollio           ###   ########.fr       */
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
	server.c += (0 << server.bit);
	//
	// 0000 1111
	// 0 0 0 0
	if (server.bit == 0)
	{
		ft_putchar_fd(server.c, 1);
		server.bit = 8;
		server.c = 0;
	}
}

void	ft_handler1()
{
	server.flag = 1;
	server.bit--;
	server.c += (1 << server.bit);
	if (server.bit == 0)
	{
		ft_putchar_fd(server.c, 1);
		server.bit = 8;
		server.c = 0;

	}
}

// void	ft_handler()
// {
// 	server.flag = 1;
// 	server.bit--;
// 	server.c += (1 << server.bit);
// 	if (server.bit == 0)
// 	{
// 		ft_putchar_fd(server.c, 1);
// 		server.bit = 8;
// 		server.c = 0;
// 	}
// }

int	main()
{
	pid_t	pid;

	// struct sigaction s_signal;
	// s_signal.sa_handler = &ft_handler;
	// s_signal.sa_flags = SA_RESTART;
	// sigemptyset(&s_signal.sa_mask);

	// 0000 1111
	server.bit = 8;
	server.flag = 2;
	server.c = 0;
	pid = getpid();

	printf("PID of the server : %d\n", pid);

	ft_putstr_fd("String received by the server : ", 1);

	while(1)
	{
		// sigaction(SIGUSR1, &s_signal, NULL);
		// sigaction(SIGUSR2, &s_signal, 0);
		signal(SIGUSR1,ft_handler0);
		signal(SIGUSR2,ft_handler1);
		pause();
	}

	return 0;
}
