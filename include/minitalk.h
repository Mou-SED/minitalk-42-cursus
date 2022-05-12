/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:20:37 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/12 22:38:29 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

# define SIGONE SIGUSR1
# define SIGZERO SIGUSR2
# define KEEP_GOING 1

int		check_get_pid(char *pid_str);
void	ft_putendl_fd(char *s, int fd);
void	send_message(char *message, pid_t pid);

#endif
