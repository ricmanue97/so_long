/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:14:16 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/10 10:47:34 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	ii;
	char	*a;

	i = 0;
	a = (char *) big;
	if (a == little)
		return (a);
	if (little[0] == '\0')
		return (a);
	while (i < len && big[i])
	{
		ii = 0;
		while (big[i] == little[ii] && i < len)
		{
			if (little[ii + 1] == '\0')
				return (a + i - ii);
			ii++;
			i++;
		}
		i = i - ii;
		i++;
	}
	return (NULL);
}
/*   int main()
{
	char big[] = "aaaaaaaabcabcd";
	char little[] = "abcd";
	char *result;

	// Search for the substring "world" in the haystack string
	result = ft_strnstr(big, little, 15);
	printf("%s\n", result);
	// Check if the substring was found
	if (result != NULL) {
		printf("Substring found at position: %ld\n", result - big);
	} else {
		printf("Substring not found.\n");
	}

	return 0;
} */
