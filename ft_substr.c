/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <ael-barh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 13:47:44 by ael-barh          #+#    #+#             */
/*   Updated: 2026/10/17 14:30:54 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	size_t i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		len = 0;
	}
	else if (len > ft_strlen(s)-start)
	{
		len = ft_strlen(s) - start;
	}
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
	{
		return NULL;
	}
	if (len == 0)
	{
		sub[i] = '\0';
	}
	else
	{
		while (i < len && s[start])
		{
			sub[i] = s[start];
			i++;
			start++;
		}
		sub[i] = '\0';
	}
	return sub;
}

int main(void)
{
	char *s = "wwwwww";
	char *sub;

	sub = ft_substr(s, 12, 5);
	printf("%s", sub);
	return 0;
}