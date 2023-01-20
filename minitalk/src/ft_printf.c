/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:49:29 by hekrem            #+#    #+#             */
/*   Updated: 2022/12/28 15:49:38 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(char s, va_list list, int *tmp)
{
	if (s == 'd')
		ft_putnbr(va_arg(list, int), tmp);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{	
			i++;
			ft_check(str[i], list, &tmp);
		}
		else
			tmp += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (tmp);
}
