/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:13:06 by wollio            #+#    #+#             */
/*   Updated: 2021/09/17 11:39:06 by wollio           ###   ########.fr       */
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

/* Structure used client side */
typedef struct	client
{
	int signal;
}				t_client;

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
#endif