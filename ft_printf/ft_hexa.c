/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:22:20 by etorun            #+#    #+#             */
/*   Updated: 2024/12/24 20:51:20 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int z, char *list)
{
	int	count;

	count = 0;
	if (z >= 16)
	{
		count += ft_hexa(z / 16, list);
	}
	count += ft_putchar(list[z % 16]);
	return (count);
}

int	ft_printp(unsigned long x, char *list)
{
	if (x == 0)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	return (ft_printp2(x, list) + 2);
}

int	ft_printp2(unsigned long x, char *list)
{
	int	count;

	count = 0;
	if (x >= 16)
	{
		count += ft_printp2(x / 16, list);
	}
	count += ft_putchar(list[x % 16]);
	return (count);
}
