/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:20:20 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/12 10:23:46 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putendl_fd("Invalid arguments", 2);
		return (-1);
	}
	pid = check_get_pid(av[1]);
	if (pid == -1)
		return (-1);
	printf("Welcome to minitalk!");
	return (0);
}
