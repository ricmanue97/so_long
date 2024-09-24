/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:18:50 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/16 12:04:22 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*a;
	size_t	size;

	size = num_elements * element_size;
	if (size && element_size && size > (UINT_MAX / element_size))
	{
		return (NULL);
	}
	a = (void *)malloc(size);
	if (!a)
		return (NULL);
	ft_bzero(a, size);
	return (a);
}
/* #include <stdio.h>
#include "libft.h"

int main()
{
	void* ptr;
	ptr = ft_calloc(10, sizeof(int));
	if (ptr)
	{
		printf("Memory allocated successfully\n");
		free(ptr);
	}
} */
