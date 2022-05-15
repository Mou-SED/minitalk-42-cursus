/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:24:13 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/15 20:08:15 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_message;

static int	len_of_unicode(char first_byt)
{
	int	i;
	int	shifted;
	int	len;

	shifted = first_byt >> 7;
	if (shifted == 0)
		return (1);
	len = 0;
	shifted = (first_byt >> 7) & 1;
	i = 6;
	while (shifted == 1 && i >= 0)
	{
		++len;
		shifted = (first_byt >> i) & 1;
		--i;
	}
	return (len);
}

static void	ft_diff_client(t_unicode *data, siginfo_t *info)
{
	ft_bzero(data, sizeof(t_unicode));
	if (g_message != NULL)
		free(g_message);
	g_message = NULL;
	data->pid_client = info->si_pid;
}

static void	ft_print_unicode(t_unicode *data)
{
	g_message[data->i_byte] = '\0';
	ft_printf("%s", g_message);
	data->i_byte = 0;
	data->len_of_uni = 0;
	if (g_message != NULL)
		free(g_message);
	g_message = NULL;
}

static void	allocate_unicode(t_unicode *data)
{
	data->len_of_uni = len_of_unicode(data->byte);
	g_message = malloc(sizeof(char) * (data->len_of_uni + 1));
	if (g_message == NULL)
		exit(1);
}

void	handle_siguser(int signum, siginfo_t *info, void *unused)
{
	static t_unicode	data;

	(void)unused;
	if (data.pid_client == 0)
		data.pid_client = info->si_pid;
	else if (info->si_pid != data.pid_client)
		ft_diff_client(&data, info);
	if (signum == SIGONE)
		data.byte = (data.byte << 1) | 1;
	else if (signum == SIGZERO)
		data.byte = (data.byte << 1);
	data.i_bit++;
	if (data.i_bit == 8 && data.byte == '\0')
		kill(data.pid_client, SIGONE);
	else if (data.i_bit == 8)
	{
		if (data.len_of_uni == 0)
			allocate_unicode(&data);
		g_message[data.i_byte++] = data.byte;
		if (data.i_byte == data.len_of_uni)
			ft_print_unicode(&data);
		data.byte = 0;
		data.i_bit = 0;
	}
}
