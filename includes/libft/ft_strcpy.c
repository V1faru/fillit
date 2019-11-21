/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:36:08 by jwilen            #+#    #+#             */
/*   Updated: 2019/11/05 14:34:09 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t i;

	if (dst == src)
		return (dst);
	i = ft_strlen(src);
	dst = ft_memcpy(dst, src, (i + 1));
	return (dst);
}
