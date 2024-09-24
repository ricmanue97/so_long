/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:44:44 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/10 11:31:39 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
//The  memchr()  function  scans  the  initial n bytes of the memory area
//pointed to by s for the first instance of c.  Both c and the  bytes  of
//the memory area pointed to by s are interpreted as unsigned char.

{
	size_t			i;
	unsigned char	*ptr2;
	unsigned char	chr;

	chr = (unsigned char)value;
	ptr2 = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		if (*ptr2 == chr)
			return (ptr2);
		ptr2++;
		i++;
	}
	return (NULL);
}

/* int main()
{
	char *str = "hello world!";
	printf("%s\n", ft_memchr(str, 'l', 3));
} */
