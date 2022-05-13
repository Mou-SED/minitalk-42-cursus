/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:24:13 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/13 17:57:38 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_siguser(int signum, siginfo_t *info, void *unused)
{
	static int		i;
	static pid_t	pid_client;
	static char		message;

	(void) unused;
	if (pid_client == 0)
		pid_client = info->si_pid;
	else if (info->si_pid != pid_client)
	{
		pid_client = info->si_pid;
		message = 0;
		i = 0;
	}
	if (signum == SIGZERO)
		message <<= 1;
	else if (signum == SIGONE)
		message = (message << 1) | 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", message);
		message = 0;
		i = 0;
	}
}
