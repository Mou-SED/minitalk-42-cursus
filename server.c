/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:19:39 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/12 22:37:29 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_siguser(int signum)
{
	printf("hi im here!");
	if (signum == SIGZERO)
		ft_putendl_fd("0", 1);
	else if (signum == SIGONE)
		ft_putendl_fd("1", 1);
}

int	main(void)
{
	struct sigaction action;
	pid_t	pid;

	pid = getpid();
	printf("PID : %d\n", pid);
	action.sa_handler = handle_siguser;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART;
	sigaction(SIGONE, &action, NULL);
	sigaction(SIGZERO, &action, NULL);
	while (KEEP_GOING)
		pause();
}
