/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:20:20 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/15 20:14:58 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_putendl_fd("Invalid arguments", STDERR_FILENO);
		return (-1);
	}
	pid = check_get_pid(av[1]);
	if (pid == -1)
		return (-1);
	if (send_message(av[2], pid) == -1)
		return (-1);
	usleep(800);
	return (0);
}
