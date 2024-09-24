/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:11:22 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/10 11:33:55 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dest);
	if (size <= dstlen)
		return (size + srclen);
	i = dstlen;
	while (i < size - 1 && *src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dstlen + srclen);
}

/* #include <stdio.h>

int main()
{
	char *src = " world!";
	char dest[14] = "Hello";
	size_t size = 13;

	ft_strlcat(dest, src, size);
	printf("%s\n", dest);
}  */
