/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:11:25 by etorun            #+#    #+#             */
/*   Updated: 2024/12/24 21:08:17 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conveyer(va_list *stuff, int ch)
{
	if (ch == 'c')
		return (ft_putchar(va_arg(*stuff, int)));
	else if (ch == 's')
		return (ft_putstr(va_arg(*stuff, char *)));
	else if (ch == 'p')
		return (ft_printp(va_arg(*stuff, unsigned long), "0123456789abcdef"));
	else if (ch == 'd' || ch == 'i')
		return (ft_putnbr(va_arg(*stuff, int)));
	else if (ch == 'u')
		return (ft_un_sign(va_arg(*stuff, int)));
	else if (ch == 'x')
		return (ft_hexa(va_arg(*stuff, unsigned int), "0123456789abcdef"));
	else if (ch == 'X')
		return (ft_hexa(va_arg(*stuff, unsigned int), "0123456789ABCDEF"));
	else if (ch == '%')
		return (ft_printper());
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	hello;

	i = 0;
	counter = 0;
	va_start(hello, str);
	while (str[i])
	{
		if (str[i] != '%')
			counter += ft_putchar(str[i]);
		else
		{
			i++;
			counter += ft_conveyer(&hello, str[i]);
		}
		i++;
	}
	va_end(hello);
	return (counter);
}
