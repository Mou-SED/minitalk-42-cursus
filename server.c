/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:19:39 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/12 20:49:56 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_siguser(int signum)
{
	if (signum == SIGZERO)
		ft_putendl_fd("0", 1);
	else if (signum == SIGONE)
		ft_putendl_fd("1", 1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID : %d\n", pid);
	signal(SIGZERO, handle_siguser);
	signal(SIGONE, handle_siguser);
	while (1)
		pause();
}
