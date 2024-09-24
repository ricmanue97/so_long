/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:21:16 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/14 09:52:45 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		length;
	char	*dest;

	length = ft_strlen (src) + 1;
	dest = malloc(sizeof(char) * (length));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, (char *) src, length);
	return (dest);
}

/* #include <stdio.h>
int main(void)
{
	char *src = "Hello World!";
	char *dest = ft_strdup(src);
	printf("This is the dupped string :%s\n", dest);
	free(dest);
}  */
