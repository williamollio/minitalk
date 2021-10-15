/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <williamollio@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:13:06 by wollio            #+#    #+#             */
/*   Updated: 2021/10/15 20:55:34 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK
# define MINITALK
# include "../libft/libft.h"
# include <signal.h>

/* Structure used server side */
typedef struct	server
{
	int bit;
	char c;
}				t_server;

#endif