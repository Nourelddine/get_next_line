/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 01:10:39 by nabdelba          #+#    #+#             */
/*   Updated: 2019/06/29 03:15:42 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# define BUFF_SIZE 16

# define RETURN_IF(x, ret) if (x) return (ret);

int		get_next_line(const int fd, char **line);

#endif
