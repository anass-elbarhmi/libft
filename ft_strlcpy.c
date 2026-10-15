/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <ael-barh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:41:14 by ael-barh          #+#    #+#             */
/*   Updated: 2026/10/15 12:41:15 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
	{
		return src_len;
	}
	while ((i < size-1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';

	return src_len;
}