/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <ael-barh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 11:45:40 by ael-barh          #+#    #+#             */
/*   Updated: 2026/10/16 11:46:42 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	init_i;
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	init_i = 0;
	while (init_i < len && big[init_i])
	{
		i = init_i;
		j = 0;
		if (big[i] == little[j])
		{
			while (i < len && big[i] == little[j] && little[j])
			{
				i++;
				j++;
			}
			if (little[j] == '\0')
				return ((char *)(big + init_i));
		}
		init_i++;
	}
	return (NULL);
}
