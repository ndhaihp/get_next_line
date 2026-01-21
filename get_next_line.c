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

char	*get_next_line(int fd)
{
	ssize_t		byte_read;
	static char *buffer;
	char		*line;
	size_t		i;
	size_t		size;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);	
	byte_read = read(fd, buffer, BUFFER_SIZE);
	i = 0;
	while (byte_read > 0)
	{
		while (i < BUFFER_SIZE && buffer[i] != '\n')
			i++;
		line = malloc(i + 1);
		if (!line)
			return (NULL);
		
		buffer[byte_read] = '\0';
	}
}
