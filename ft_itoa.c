#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char *ft_itoa(int n)
{
	long nb;
	long n_fix;
	int signe;
	int len;
	char *p;

	nb = n;
	n_fix = n;
	signe = 1;
	len = 0;
	if (nb == 0)
	{
		p = (char *)malloc(sizeof(char)*2);
		if (!p)
			return p;
		p[0] = '0';
		p[1] = '\0';
		return p;
	}
	
	if (nb < 0)
	{
		nb = -nb;
		n_fix = -n_fix;
		signe = -1;
		len++;
	}
	while ((nb > 0))
	{
		nb = nb / 10;
		len++;
	}
	p = (char *)malloc(sizeof(char)*(len+1));
	if (!p)
		return NULL;
	
	if (signe < 0)
		p[0] = '-';
	p[len] = '\0';
	while (n_fix > 0)
	{
		p[--len] = (n_fix % 10) + '0';
		n_fix = n_fix / 10;
	}
	return p;
}
int main()
{
	int n;
	char *p;

	n = 0;
	p = ft_itoa(n);
	printf("%s",p);

}