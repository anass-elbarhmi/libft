/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>

static int	ft_count_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
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
	p[len] = '\0';
	if (nb == 0)
	{
		p[0] = '0';
	}
	if (nb < 0)
	{
		p[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		p[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return p;
}

int main(void)
{
	int nb = -42;
	char *p;
	p = ft_itoa(nb);
	printf("%d",ft_count_len(nb));
	printf("%s",p);
}
