/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:20:37 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/15 20:00:01 by moseddik         ###   ########.fr       */
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

# define GREEN "\e[0;32m"
# define RED "\e[1;31m"
# define NC "\e[0m"

typedef struct s_unicode
{
	pid_t	pid_client;
	int		i_bit;
	char	byte;
	int		i_byte;
	int		len_of_uni;
}	t_unicode;

int		check_get_pid(char *pid_str);
void	ft_putendl_fd(char *s, int fd);
int		send_message(char *message, pid_t pid);
void	handle_siguser(int signum, siginfo_t *info, void *unused);
void	confirm_message(int signum);
void	ft_bzero(void *s, size_t n);

#endif
