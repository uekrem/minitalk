/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:33:48 by hekrem            #+#    #+#             */
/*   Updated: 2022/12/28 23:33:49 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "./src/ft_printf.h"

void	ft_signal(int signal)
{
	static char	y;
	static int	count;

	y <<= 1;
	if (signal == SIGUSR1)
		y |= 1;
	count++;
	if (count == 8)
	{
		write(1, &y, 1);
		count = 0;
		y = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID:%d\n", pid);
	while (42)
	{
		signal(SIGUSR1, ft_signal);
		signal(SIGUSR2, ft_signal);
		pause();
	}
}
