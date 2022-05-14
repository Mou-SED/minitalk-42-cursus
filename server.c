/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:19:39 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/14 07:57:17 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	action;
	pid_t				pid;

	pid = getpid();
	ft_printf("%s\nPID : %d\n%s", RED, pid, NC);
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGZERO);
	sigaddset(&action.sa_mask, SIGONE);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handle_siguser;
	sigaction(SIGONE, &action, NULL);
	sigaction(SIGZERO, &action, NULL);
	while (KEEP_GOING)
		pause();
}
