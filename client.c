/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:42:45 by wollio            #+#    #+#             */
/*   Updated: 2021/09/14 15:47:29 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <sys/types.h>


/* Reverse a string */
void	ft_revers(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

/* Convert integer to binary */
char	*int_to_bin(int c)
{
	char	*bin;
	int		i;

	bin = (char *)malloc(8);
	i = 0;
	while(c > 0)
	{
		bin[i] = c % 2 + '0';
		c /= 2;
		i++;
	}
	ft_revers(bin);
	return (bin);
}

/* Appends two strings */
char	*ft_append(char *str, char *bin, char *tmp)
{
	tmp = ft_strjoin(str, bin);
	free(str);
	str = tmp;
	return (str);
}

/* Go trough the string and send it to the server as signals */
void ft_sending(char *str, pid_t pid)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '0')
			kill(pid, SIGUSR1);

		else if (str[i] == '1')
			kill(pid, SIGUSR2);
		usleep(1000);
		i++;
	}
	return;
}

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		pid_t	pid;
		char	*string;
		int		length_string;
		char	*bin;
		char	*tmp;
		char	*str;
		int 	i;

		i = 0;
		tmp = NULL;
		/* Pass PID from char to int */
		pid = ft_atoi(argv[1]);
		printf("PID of the server : %d\n", pid);

		/* Transfer the input into the varible string and get the length of it */
		string = argv[2];
		length_string = ft_strlen(string);
		//printf("length_string : %d\n", length_string);

		/* Convert the string into its binary value */
		str = malloc(8);
		while (i < length_string)
		{
		 	bin = int_to_bin(string[i]);
			str = ft_append(str, bin, tmp);
			i++;
			free(bin);
			free(tmp);
		}
		printf("String sent to the server : %s\n", str);
		free(str);
		ft_sending(str, pid);
	}
	else
		write(1,"./client pid string\n", 20);
	//fscanf(stdin, "c");
	printf("---- Data sent to the server ----\n");
	return 0;
}