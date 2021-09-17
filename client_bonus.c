/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:42:45 by wollio            #+#    #+#             */
/*   Updated: 2021/09/17 15:16:24 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <stdio.h>
#include <sys/types.h>

/* Handle each signal receive from the server */
void ft_handler()
{
	ft_putstr_fd(" -- Signals well received -- \n", 1);
	exit(EXIT_SUCCESS);
}

/* Send each characters bit by bit with a bitwise operator */
void ft_sending(char c, pid_t pid_server)
{
	int i;

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
	return;
}

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		struct sigaction s_signal;

		pid_t	pid_server;
		int		length_string;
		int 	i;

		s_signal.sa_handler = &ft_handler;
		i = 0;
		while(1)
		{
			sigaction(SIGUSR2, &s_signal, NULL);
			while (i <= ft_strlen(*argv[2]))
			{
				ft_sending(argv[2][i], ft_atoi(argv[1]));
				i++;
			}
			pause();
		}
	}
	else
		write(1,"./client pid string\n", 20);
	return 0;
}
