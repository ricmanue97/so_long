/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:55:45 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/14 09:52:49 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* #include <stdio.h>
void        print_index_and_char(unsigned int index, char *c)
{
        printf("Index: %d, Char: %c\n", index, *c);
}
int        main(void)
{
        char        str[] = "Hello, World!";
        ft_striteri(str, &print_index_and_char);
        return (0);
} */
