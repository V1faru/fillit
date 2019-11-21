/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:02:17 by jwilen            #+#    #+#             */
/*   Updated: 2019/11/05 12:23:01 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	size_t			str_len;
	unsigned int	n2;

	n2 = n;
	str_len = ft_getintlen(n);
	if (n < 0)
	{
		n2 = -n;
		str_len++;
	}
	if (!(str = ft_strnew(str_len)))
		return (NULL);
	str[--str_len] = n2 % 10 + '0';
	while (n2 /= 10)
		str[--str_len] = n2 % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
