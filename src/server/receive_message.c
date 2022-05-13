/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:24:13 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/13 18:13:43 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_message;

void	handle_siguser(int signum, siginfo_t *info, void *unused)
{
	static int		i;
	static pid_t	pid_client;

	(void) unused;
	if (pid_client == 0)
		pid_client = info->si_pid;
	else if (info->si_pid != pid_client)
	{
		pid_client = info->si_pid;
		g_message = 0;
		i = 0;
	}
	if (signum == SIGZERO)
		g_message <<= 1;
	else if (signum == SIGONE)
		g_message = (g_message << 1) | 1;
	i++;
	if (i == 8)
	{
		if (g_message == '\0')
			kill(pid_client, SIGONE);
		ft_printf("%c", g_message);
		g_message = 0;
		i = 0;
	}
}
