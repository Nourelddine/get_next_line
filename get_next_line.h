/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:58:41 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/18 22:58:41 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
#include "./libft/libft.h"
#include <fcntl.h> 
#include <unistd.h>

# define BUFFER_SIZE 32

int		get_next_line(const int fd, char **line);

# endif

