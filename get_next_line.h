/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h       	 				 		    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainguye <dainguye@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:57:58 by dainguye          #+#    #+#             */
/*   Updated: 2025/11/16 10:57:58 by dainguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);

#endif