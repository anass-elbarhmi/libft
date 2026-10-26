/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

void *my_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return s;
}
void *fff(void *s, int c, size_t n)
{

	unsigned char *p;
	p = s;
	while (n--)
	{
		*(p++) = c;
			
	}
	return s;
}

void *my_memcpy(void *dest, void const *src, size_t n)
{
	size_t i;

	i = 0;
	if (dest == NULL && src == NULL)
	{
		return NULL;
	}
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return dest;
	
}
void *my_memmove(void *dest, void *src,size_t n)
{
	if (dest == NULL && src == NULL)
	{
		return NULL;
	}
	if (dest <= src)
	{
		my_memcpy(dest,src,n);
	}
	else
	{
		if (n == 0)
		{
			return dest;
		}
		n--;
		while (n > 0)
		{
			((unsigned char *)dest)[n] = ((const unsigned char *)src)[n];
			n--;
		}
		((unsigned char *)dest)[n] = ((const unsigned char *)src)[n];
	}
	return dest;
}

int main(void)
{
	char src[] = "anass";
	char dest[] = "elbarhmi" ;

	my_memmove(dest,src,3);
	printf("%s",dest);

	return 0;
}
