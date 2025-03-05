/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:11:06 by etorun            #+#    #+#             */
/*   Updated: 2025/02/20 23:25:52 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)str1)[i] != ((unsigned char *)str2)[i]))
			return (((unsigned char *)str1)[i]
				- ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}
