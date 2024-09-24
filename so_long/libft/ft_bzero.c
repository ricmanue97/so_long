/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:46:12 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/14 09:51:12 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/* #include <stdio.h>

int main()
{
	char str[10] = "hello";
	printf("Before: %s\n", str);
	ft_bzero(str, 5);
	printf("After: %s\n", str);
} */
