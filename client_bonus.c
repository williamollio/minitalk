/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:42:45 by wollio            #+#    #+#             */
/*   Updated: 2021/09/17 15:09:29 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <stdio.h>
#include <sys/types.h>

//static	t_client client;

/* Handle each signal receive from the server */
void ft_handler()
{
	// if (sig == SIGUSR1)
	// 	ft_putstr_fd("S\n", 1);
	// else if (sig == SIGUSR2)
	// 	exit(EXIT_SUCCESS);
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
		char	*string;
		int		length_string;
		int 	i;

		s_signal.sa_handler = &ft_handler;

		pid_server = ft_atoi(argv[1]);
		string = argv[2];
		length_string = ft_strlen(string);

		i = 0;
		while(1)
		{
			if (sigaction(SIGUSR1, &s_signal, NULL) ||
			sigaction(SIGUSR2, &s_signal, NULL) < 0)
			{
				ft_putendl_fd("An error has occurred", 1);
				exit(EXIT_FAILURE);
			}
			while (i <= length_string)
			{
				ft_sending(string[i], pid_server);
				i++;
			}
			pause();
		}
	}
	else
		write(1,"./client pid string\n", 20);
	return 0;
}
