/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:01:30 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/12 14:48:02 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_byte(char byte, pid_t	pid)
{
	int		i;
	char	shifted_bit;
	int		kill_ret;

	i = 7;
	while (i >= 0)
	{
		printf("Send\n");
		shifted_bit = (byte >> i) & 1;
		if (shifted_bit == 1)
			kill_ret = kill(pid, SIGONE);
		else
			kill_ret = kill(pid, SIGZERO);
		if (kill_ret == -1)
		{
			ft_putendl_fd("Error: Kill Failed", STDERR_FILENO);
			return (-1);
		}
		usleep(800);
		i--;
	}
	return (0);
}

void	send_message(char *message, pid_t pid)
{
	int	i;

	i = -1;
	while (message[++i] != '\0')
	{
		send_byte(message[i], pid);
	}
}
