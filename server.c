/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:19:39 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/12 14:47:44 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_siguser1(int signum)
{
	printf("Signal %d recived.\n", signum);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID : %d\n", pid);
	signal(SIGONE, handle_siguser1);
	signal(SIGZERO, handle_siguser1);
	while (1)
		pause();
}
