/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:02:29 by ricmanue          #+#    #+#             */
/*   Updated: 2024/04/22 15:29:05 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	int				res;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && str1[i] && i + 1 < n)
		i++;
	res = s1[i] - s2[i];
	return (res);
}

/*  #include <stdio.h>

int main()
{
	char *s = "abcdef";
	char *s1 = "abcdefautruqwegq";
	printf("%d\n", ft_strncmp(s, s1, 6));
	printf("%d\n", strncmp(s, s1, 6));
} */
