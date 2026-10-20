/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <ael-barh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:46:13 by ael-barh          #+#    #+#             */
/*   Updated: 2026/10/20 20:46:14 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if ((nb / 10) > 0)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	c = (nb % 10) + '0';
	write(fd, &c, 1);
	return ;
}
