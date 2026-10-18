/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <ael-barh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 10:37:11 by ael-barh          #+#    #+#             */
/*   Updated: 2026/10/18 10:38:13 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total;
	char	*joined;

	total = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(total + 1);
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, total + 1);
	ft_strlcat(joined, s2, total + 1);
	return (joined);
}
