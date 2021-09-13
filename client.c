/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:42:45 by wollio            #+#    #+#             */
/*   Updated: 2021/09/13 17:14:16 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int pid;
		pid = ft_atoi(argv[1]);
		printf("PID %d", pid);
	}
	else
		write(1,"./client pid string\n", 20);
	return 0;
}