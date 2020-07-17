/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:47:03 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/14 21:27:12 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen(s);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		lenstr;
	int		lens1;
	int		lens2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	lenstr = 0;
	lens1 = -1;
	while (s1[++lens1])
		lenstr++;
	lens2 = -1;
	while (s2[++lens2])
		lenstr++;
	str = (char *)malloc(lenstr + 1);
	if (!str)
		return (NULL);
	ft_strncpy(str, s1, lens1 + 1);
	ft_strlcat(str, s2, lenstr + 1);
	free(s1);
	return (str);
}

void	ft_strncpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = ft_strlen(dst);
	x = ft_strlen(src);
	x = x + i;
	if (i > size)
		x = x - i + size;
	j = 0;
	while (src[j] != '\0' && (i + 1) < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (x);
}
