/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:46:57 by ricmanue          #+#    #+#             */
/*   Updated: 2024/04/11 12:46:58 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char *) s;
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (&s1[i]);
	return (0);
}
/* #include <stdio.h>

int main(void)
{
    const char *s = "Hello World!";
    int c = 'l';

    printf("%s\n", ft_strchr(s, c));
    printf("%s\n", strchr(s, c));
} */
