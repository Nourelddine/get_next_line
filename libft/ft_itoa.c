/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:17:14 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/17 21:45:34 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		num;

	i = 0;
	num = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		num = -n;
	if (!(str = ft_strnew(ft_intlen(n))))
		return (NULL);
	while (num > 0)
	{
		str[i] = (num % 10) + 48;
		num = num / 10;
		i++;
	}
	if (n < 0)
		str[i++] = '-';
	else if (n == 0)
		str[0] = '0';
	return (ft_strrev(str));
}
