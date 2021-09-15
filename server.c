/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:22 by wollio            #+#    #+#             */
/*   Updated: 2021/09/15 20:17:44 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <sys/types.h>

static	t_server server;


void	ft_handler(int sig, siginfo_t *siginfo, void *context)
{
	printf ("Sending PID: %ld, UID: %ld\n",(long)siginfo->si_pid, (long)siginfo->si_uid);

	(void)context;
	if (sig == SIGUSR1)
		server.flag = 0;
	else if (sig == SIGUSR2)
		server.flag = 1;
	server.bit--;
	server.c += (server.flag << server.bit);
	if (server.bit == 0)
	{
		ft_putchar_fd(server.c, 1);
		server.bit = 8;
		server.c = 0;
	}
}

int	main()
{
	pid_t	pid;

	struct sigaction s_signal;

	/* Use the sa_sigaction field because the handles has two additional parameters */
	s_signal.sa_sigaction = &ft_handler;

	/* The SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not sa_handler. */
	s_signal.sa_flags = SA_SIGINFO;


	server.bit = 8;
	server.c = 0;
	pid = getpid();

	printf("PID of the server : %d\n", pid);

	ft_putstr_fd("String received by the server : ", 1);

	while(1)
	{
		sigaction(SIGUSR1, &s_signal, NULL);
		sigaction(SIGUSR2, &s_signal, 0);
		pause();
	}

	return 0;
}
