/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:20:37 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/13 16:05:00 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# include "ft_printf.h"

# define SIGONE SIGUSR1
# define SIGZERO SIGUSR2
# define KEEP_GOING 1

int		check_get_pid(char *pid_str);
void	ft_putendl_fd(char *s, int fd);
int		send_message(char *message, pid_t pid);
void	handle_siguser(int signum, siginfo_t *info, void *unused);

#endif
