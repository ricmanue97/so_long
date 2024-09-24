/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:53:41 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/14 09:52:16 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *c, int d, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *) c;
	while (len != 0)
	{
		str[len - 1] = d;
		len--;
	}
	return (str);
}

/* int main()
{
	char str[12] = "Hello World";
	size_t len = 11;
	printf("%s\n", str);
	printf("%s\n", ft_memset(str, 48, len));

} */
