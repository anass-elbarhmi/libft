/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <ael-barh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:00:46 by ael-barh          #+#    #+#             */
/*   Updated: 2026/10/27 17:03:30 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while ((n / 10) > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*p;

	nb = n;
	len = ft_count_len(nb);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		p[0] = '-';
	}
	p[len] = '\0';
	len--;
	while (len >= 0)
	{
		if (p[len] == '-')
			return (p);
		p[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (p);
}
