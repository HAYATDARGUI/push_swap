/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:39:15 by hdargui           #+#    #+#             */
/*   Updated: 2025/01/26 15:18:32 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_data(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_strjoin2(const char *s1, const char *s2)
{
	char	*s3;
	int		len1;
	int		len2;

	len1 = 0;
	len2 = 0;
	if (s1)
		while (s1[len1])
			len1++;
	if (s2)
		while (s2[len2])
			len2++;
	if (!s1 && !s2)
		return (NULL);
	s3 = malloc(len1 + len2 + 1);
	if (!s3)
		return (NULL);
	if (s1)
		ft_strcpy2(s3, s1);
	if (s2)
		ft_strcpy2(s3 + len1, s2);
	s3[len1 + len2] = '\0';
	free((void *)s1);
	return (s3);
}

char	*ft_read_to_save(int fd, char *save)
{
	char	*buffer;
	int		num_bytes;
	char	*tmp;

	num_bytes = 1;
	while (num_bytes > 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes == -1)
			return (free_data((void **)&buffer), free_data((void **)&save),
				NULL);
		if (num_bytes == 0)
			break ;
		buffer[num_bytes] = '\0';
		tmp = save;
		save = ft_strjoin2(save, buffer);
		free_data((void **)&buffer);
		if (!save)
			return (free(tmp), save = NULL, NULL);
		if (ft_strchr(save, '\n'))
			break ;
	}
	free(buffer);
	return (save);
}

char	*extract_line(char **save)
{
	char	*line;
	char	*new_save;
	int		i;

	i = 0;
	if (*save == NULL || **save == '\0')
		return (NULL);
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	if ((*save)[i] == '\n')
	{
		line = ft_substr2(*save, 0, i + 1);
		new_save = ft_strdup2(&(*save)[i + 1]);
		free(*save);
		*save = new_save;
		return (line);
	}
	else if ((*save)[i] == '\0')
	{
		line = ft_strdup2(*save);
		free(*save);
		*save = NULL;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	save[fd] = ft_read_to_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = extract_line(&save[fd]);
	if (!line)
	{
		free(save[fd]);
		save[fd] = NULL;
	}
	return (line);
}
