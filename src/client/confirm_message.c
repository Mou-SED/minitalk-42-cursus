/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:02:57 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/13 18:19:38 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	confirm_message(int signum)
{
	if (signum == SIGONE)
		ft_printf("%sReceived confirmation from server\n%s", GREEN, NC);
}
