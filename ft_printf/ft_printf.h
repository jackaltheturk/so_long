/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:28:52 by etorun            #+#    #+#             */
/*   Updated: 2024/12/25 15:29:13 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printper(void);
int	ft_putchar(int x);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_hexa(unsigned int z, char *list);
int	ft_un_sign(unsigned int nb);
int	ft_printp(unsigned long x, char *list);
int	ft_printp2(unsigned long x, char *list);
int	ft_conveyer(va_list *stuff, int ch);
int	ft_printf(const char *str, ...);

#endif