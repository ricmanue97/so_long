/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:20:05 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/17 11:39:56 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *s, char c)
{
	int	i;
	int	trigger;
	int	count;

	if (!s)
		return (0);
	i = 0;
	trigger = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (s[i] == c)
			trigger = 0;
		i++;
	}
	return (count);
}

static char	**actualsplit(char *s, int c, char **result)
{
	size_t	wordlen;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				wordlen = ft_strlen(s);
			else
				wordlen = ft_strchr(s, c) - s;
			result[i++] = ft_substr(s, 0, wordlen);
			s += wordlen;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*str;

	str = (char *)s;
	if (!s)
		return (NULL);
	result = (char **)malloc((countwords(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = actualsplit(str, c, result);
	return (result);
}

/* int	main(void)
{
	char	**result;
	char	input[] = "";
	int		i;

	result = ft_split(input, ' ');
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
} */
