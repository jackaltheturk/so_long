/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:28:17 by etorun            #+#    #+#             */
/*   Updated: 2025/02/20 23:26:47 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	counter;
	char	*ptr;

	counter = 0;
	ptr = (char *)b;
	while (counter != len)
	{
		ptr[counter] = c;
		counter++;
	}
	return (b);
}
