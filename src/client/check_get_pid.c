/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_get_pid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:18:06 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/12 10:25:45 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	int		r;
	char	*ptr;

	ptr = (char *)str;
	i = 0;
	s = 1;
	r = 0;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32)
		i++;
	while ((ptr[i] == '-') || (str[i] == '+'))
	{
		if (ptr[i] == '-')
			s = s * -1;
		if (ptr[i + 1] == '-' || ptr[i + 1] == '+')
			return (0);
		i++;
	}
	while ((ptr[i] >= '0') && (ptr[i] <= '9'))
	{
		r = (r * 10) + (ptr[i] - '0');
		i++;
	}
	return (r * s);
}

static int	is_plus_or_minus(int c)
{
	if (c == '+' || c == '-')
		return (!0);
	return (0);
}

static int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (!0);
	else
		return (0);
}

static int	check_error(char *str)
{
	int	value;

	if (str != NULL && str[0] == '\0')
		return (1);
	value = 0;
	if (is_plus_or_minus(*str) && !ft_isdigit(*(str + 1)))
		return (1);
	if (is_plus_or_minus(*str) && str++)
		value = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			value = 1;
		str++;
	}
	return (value);
}

int	check_get_pid(char *pid_str)
{
	int	pid;

	if (check_error(pid_str))
	{
		ft_putendl_fd("Invalid PID", 2);
		return (-1);
	}
	pid = ft_atoi(pid_str);
	if (pid < 0)
	{
		ft_putendl_fd("Invalid PID", 2);
		return (-1);
	}
	return (pid);
}
