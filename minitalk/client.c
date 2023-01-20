/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:05:08 by hekrem            #+#    #+#             */
/*   Updated: 2022/12/28 23:05:10 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *nptr)
{
	long	i;
	long	mark;
	long	value;

	value = 0;
	mark = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			mark *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = (value * 10) + (nptr[i] - '0');
		if (value * mark < -2147483648)
			return (0);
		else if (value * mark > 2147483647)
			return (-1);
		i++;
	}
	return (value * mark);
}

int	main(int argc, char **argv)
{
	int		index;
	int		swap;
	pid_t	pid;

	index = 0;
	pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		while (argv[2][index])
		{
			swap = 7;
			while (swap >= 0)
			{
				if ((argv[2][index] >> swap) & 1)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				usleep(100);
				swap--;
			}
			index++;
		}
	}
}
