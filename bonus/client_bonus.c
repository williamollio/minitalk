/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <williamollio@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:42:45 by wollio            #+#    #+#             */
/*   Updated: 2021/10/15 20:54:45 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"
#include <stdio.h>
#include <sys/types.h>

/* Handle the signal receive from the server */
void	ft_handler(int signal)
{
	(void)signal;
	ft_putstr_fd(" -- Signals well received -- \n", 1);
	exit(EXIT_SUCCESS);
}

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
	struct sigaction	s_signal;
	int					i;

	if (argc == 3)
	{
		s_signal.sa_handler = &ft_handler;
		i = 0;
		while (1)
		{
			sigaction(SIGUSR2, &s_signal, NULL);
			while (i <= (int)ft_strlen(argv[2]))
			{
				ft_sending(argv[2][i], ft_atoi(argv[1]));
				i++;
			}
			pause();
		}
	}
	else
		write(1, "./client pid string\n", 20);
	return (0);
}
