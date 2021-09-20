/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:13:06 by wollio            #+#    #+#             */
/*   Updated: 2021/09/20 10:41:11 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS
# define MINITALK_BONUS
# include "./libft/libft.h"
# include <signal.h>

/* Structure used server side */
typedef struct	server
{
	int flag;
	int bit;
	char c;
}				t_server;

/* Structure of sigaction
**
**	struct sigaction {
**		void     (*sa_handler)(int);
**		void     (*sa_sigaction)(int, siginfo_t *, void *);
**		sigset_t   sa_mask;
**		int        sa_flags;
**		void     (*sa_restorer)(void);
**	};
*/

/* You can set sa_mask in your sigaction call to block certain signals while a particular signal handler runs.
This way, the signal handler can run without being interrupted itself by signals.
sigemptyset(&s_signal.sa_mask); */

/* The SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not sa_handler.
s_signal.sa_flags = SA_SIGINFO; */

/* Use the sa_sigaction field because the handles has two additional parameters
s_signal.sa_sigaction = &ft_handler; */

#endif