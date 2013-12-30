/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 23:14:55 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/11/30 15:26:36 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_how_many(const char *s, char c);
static int	ft_mod_strlen(const char *s, char c);

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	tab = (char **)malloc((ft_how_many(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab[ft_how_many(s, c)] = NULL;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j++] = ft_strsub(s, i, ft_mod_strlen(&s[i], c));
			i += ft_mod_strlen(&s[i], c) - 1;
		}
		i++;
	}
	return (tab);
}

static int	ft_how_many(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
		if (s[i] != 0)
			i++;
	}
	return (j);
}

int		ft_mod_strlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}
