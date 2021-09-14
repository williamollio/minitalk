/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:22 by wollio            #+#    #+#             */
/*   Updated: 2021/09/14 15:39:10 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <sys/types.h>


int flag = 2;

void	ft_handler0()
{
	flag = 0;
}

void	ft_handler1()
{
	flag = 1;
}
int	main()
{
	pid_t pid;

	pid = getpid();
	printf("PID of the server : %d\n", pid);
	signal(SIGUSR1, ft_handler0);
	signal(SIGUSR2, ft_handler1);

	printf("String received by the server : ");
	while(1)
	{
		if (flag == 0)
		{
			ft_putnbr_fd(0, 1);
		}
		else if (flag == 1)
		{
			ft_putnbr_fd(1, 1);
		}
		pause();
	}

	return 0;
}
