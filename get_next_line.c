/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c    	       	 		 		    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainguye <dainguye@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:57:58 by dainguye          #+#    #+#             */
/*   Updated: 2025/11/11 10:57:58 by dainguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*scoop_data(int fd, char *buffer)
{
	ssize_t		byte_read;
	char		*chunk;
	char		*temp;

	if (!buffer)
		buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	chunk = malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return (free(buffer), NULL);
	byte_read = 1;
	while (byte_read > 0 && ft_strchr(buffer, ',') == NULL)
	{
		byte_read = read(fd, chunk, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(chunk), free(buffer), NULL);
		chunk[byte_read] = '\0';
		temp = buffer;
		buffer = ft_strjoin(temp, chunk);
		free(temp);
		if (!buffer)
			return (free(chunk), NULL);
	}
	return (free(chunk), buffer);
}

char	*extract_line(char *buffer)
{
	char	*line;
	size_t	i;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != ',')
		i++;
	line = ft_substr(buffer, 0, i + (buffer[i] == ','));
	return (line);
}

char	*extract_buffer(char *buffer)
{
	char	*new_buffer;
	size_t	i;	

	i = 0;
	while (buffer[i] && buffer[i] != ',')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	new_buffer = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	free(buffer);
	if (new_buffer && !*new_buffer)
		return (free(new_buffer), NULL);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = scoop_data(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = extract_buffer(buffer);
	return (line);
}
