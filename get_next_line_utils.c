/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olskor <olskor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:37:31 by olskor            #+#    #+#             */
/*   Updated: 2023/02/25 18:53:53 by olskor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *) s + i);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	len;

	len = (size_t)(size * nmemb);
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (len / size != nmemb || len / nmemb != size)
		return (NULL);
	tab = malloc(len);
	if (tab)
		ft_bzero(tab, len);
	return (tab);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*rst;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	rst = (char *)malloc(len + 1);
	i = 0;
	if (!rst)
		return (NULL);
	while (s1[i])
	{
		rst[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len])
	{
		rst[i + len] = s2[len];
		len++;
	}
	rst[i + len] = 0;
	return (rst);
}
