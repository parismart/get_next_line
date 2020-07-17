/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:28:41 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/14 21:01:44 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

static int	copy_line(char **remind, char **line, int fd)
{
	int		i;
	char	*ptr;

	i = 0;
	while (remind[fd][i] != '\n' && remind[fd][i] != '\0')
		i++;
	if (!(*line = (char *)malloc(i + 1)))
		return (-1);
	ft_strncpy(*line, remind[fd], i + 1);
	ptr = ft_strchr(remind[fd], '\n');
	if (ptr)
	{
		ptr = ft_strdup(ptr + 1);
		free(remind[fd]);
		remind[fd] = ptr;
		return (1);
	}
	free(remind[fd]);
	remind[fd] = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*remind[4096];
	int			nbytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!line || fd < 0 || !buffer || BUFFER_SIZE <= 0)
		return (-1);
	while ((nbytes = read(fd, buffer, BUFFER_SIZE)) && nbytes > 0)
	{
		buffer[nbytes] = '\0';
		if (!remind[fd])
			remind[fd] = ft_strdup(buffer);
		else
			remind[fd] = ft_strjoin(remind[fd], buffer);
		if (ft_strchr(remind[fd], '\n'))
			break ;
	}
	free(buffer);
	if (nbytes < 0)
		return (-1);
	else if (nbytes > 0 || (nbytes == 0 && remind[fd]))
		return (copy_line(remind, line, fd));
	*line = ft_strdup("");
	return (0);
}
