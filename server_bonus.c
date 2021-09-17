/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:22 by wollio            #+#    #+#             */
/*   Updated: 2021/09/17 15:13:53 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <stdio.h>
#include <sys/types.h>

static	t_server server;


void	ft_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		server.flag = 0;
	else if (sig == SIGUSR2)
		server.flag = 1;
	server.bit--;
	server.c += (server.flag << server.bit);
	if (server.bit == 0)
	{
		if (!server.c)
		{
			ft_putchar_fd('\n', 1);
			kill(siginfo->si_pid, SIGUSR2);
		}
		ft_putchar_fd(server.c, 1);
		server.bit = 8;
		server.c = 0;
	}
}

int	main()
{
	pid_t	pid;

	struct sigaction s_signal;

	ft_memset(&s_signal, '\0', sizeof(s_signal));
	sigemptyset(&s_signal.sa_mask);

	/* Use the sa_sigaction field because the handles has two additional parameters */
	s_signal.sa_sigaction = &ft_handler;

	/* The SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not sa_handler. */
	s_signal.sa_flags = SA_SIGINFO;

	server.bit = 8;
	server.c = 0;
	pid = getpid();
	ft_putstr_fd("---- Lauching of the server ----", 1);
	ft_putstr_fd("\n	------------- ", 1);
	ft_putstr_fd("\n       -- [Minitalk] -- \n", 1);
	ft_putstr_fd("	------------- ", 1);
	ft_putstr_fd("\n -- PID of the server : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd(" -- \n", 1);
	ft_putstr_fd("	------------- ", 1);
	ft_putstr_fd("\n -- Waiting for signals -- \n", 1);
	ft_putstr_fd("	------------- \n", 1);
	while(1)
	{
		sigaction(SIGUSR1, &s_signal, NULL);
		sigaction(SIGUSR2, &s_signal, NULL);
		pause();
	}
	return (0);
}
