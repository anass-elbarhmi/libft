#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int ft_count_len(long n)
{
	int len = 1;
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
	return len;
}
char *ft_itoa(int n)
{
	long nb;
	int signe;
	int len;
	char *p;

	nb = n;
	signe = 1;
	len = 0;

	len = ft_count_len(nb);
	p = (char *)malloc(sizeof(char)*(len+1));
	if (!p)
		return NULL;
	
	if (signe < 0)
		p[0] = '-';
	p[len] = '\0';
	while (nb > 0)
	{
		p[--len] = (nb % 10) + '0';
		nb = nb / 10;
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