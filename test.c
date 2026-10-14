/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <ael-barh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:59:44 by ael-barh          #+#    #+#             */
/*   Updated: 2026/10/14 11:00:51 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

void *ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return	s;
}

int	main(void)
{
	size_t i = 0;
	char str[] = "anasssssssssssssss";
	ft_memset(str, '1', 10);
	while (str[i])
	{
		printf("%c",str[i]);
		i++;
	}
	

	return 0;
}