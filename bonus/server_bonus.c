/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <williamollio@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:22 by wollio            #+#    #+#             */
/*   Updated: 2021/10/16 21:35:40 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"
#include <stdio.h>
#include <sys/types.h>

static t_server	g_server;

/* Launching of the server and variables initialization */
void	ft_init(void)
{
	pid_t	pid;

	g_server.bit = 8;
	g_server.c = 0;
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
}

/* Decoding and sending signal */
void	ft_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		g_server.flag = 0;
	else if (sig == SIGUSR2)
		g_server.flag = 1;
	g_server.bit--;
	g_server.c += (g_server.flag << g_server.bit);
	if (g_server.bit == 0)
	{
		if (!g_server.c)
		{
			ft_putchar_fd('\n', 1);
			/* Signal to the client */
			kill(siginfo->si_pid, SIGUSR2);
		}
		ft_putchar_fd(g_server.c, 1);
		g_server.bit = 8;
		g_server.c = 0;
	}
}

int	main(void)
{
	struct sigaction	s_signal;

	ft_memset(&s_signal, '\0', sizeof(s_signal));
	sigemptyset(&s_signal.sa_mask);

	/* The SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not sa_handler. */
	s_signal.sa_flags = SA_SIGINFO;

	/*Use the sa_sigaction field because the handles has two additional parameters */
	s_signal.sa_sigaction = &ft_handler;
	ft_init();
	while (1)
	{
		sigaction(SIGUSR1, &s_signal, NULL);
		sigaction(SIGUSR2, &s_signal, NULL);
		pause();
	}
	return (0);
}
