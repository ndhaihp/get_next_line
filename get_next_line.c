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

char	*scoop_data(int fd)
{
	ssize_t		byte_read;
	static char *buffer;
	char		*chunk;
	char		*temp;

	chunk = malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0 && ft_strchr(chunk, '\n') == NULL)
	{
		byte_read = read(fd, chunk, BUFFER_SIZE);
		if (byte_read <= 0)
			return (NULL);
		chunk[byte_read] = '\0';
		temp = buffer;
		buffer = ft_strjoin(temp, chunk);
		free(temp);
	}
	return(buffer);
}

char	*extract_line(char *buffer, size_t *tail)
{
	char	*line;
	size_t	i;

	i = 0;
	while (buffer[i] != '\n' || buffer[i] != '\0')
		i++;
	line = ft_strndup(buffer, i + 1);
	*tail = ft_strlen(buffer) - i;
	return(line);
}

char	*get_next_line
{

}
