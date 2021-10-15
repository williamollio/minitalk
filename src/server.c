/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <williamollio@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:22 by wollio            #+#    #+#             */
/*   Updated: 2021/10/15 20:55:22 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
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
	ft_putstr_fd("PID of the server : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("String received by the server : ", 1);
}

/* Handle and decode the SIGUSR2 signals */
void	ft_handler0(int signal)
{
	(void)signal;
	g_server.bit--;
	g_server.c += (0 << g_server.bit);
	if (g_server.bit == 0)
	{
		ft_putchar_fd(g_server.c, 1);
		g_server.bit = 8;
		g_server.c = 0;
	}
}

/* Handle and decode the SIGUSR2 signals */
void	ft_handler1(int signal)
{
	(void)signal;
	g_server.bit--;
	g_server.c += (1 << g_server.bit);
	if (g_server.bit == 0)
	{
		ft_putchar_fd(g_server.c, 1);
		g_server.bit = 8;
		g_server.c = 0;
	}
}

int	main(void)
{
	ft_init();
	while (1)
	{
		signal(SIGUSR1, ft_handler0);
		signal(SIGUSR2, ft_handler1);
		pause();
	}
	return (0);
}
