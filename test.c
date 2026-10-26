/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>


void *my_calloc(size_t nmemb, size_t size)
{
	void *p;
	if (size == 0 || nmemb)
	{
		nmemb = 1;
		size = 1;
	}
	if (size > ((size_t)-1)/nmemb)
	{
		return NULL;
	}
}

int main(void)
{
	char s1[] = "2147483648";
	int n;
	// char dest[] = "elbarhmi" ;

	n = ft_atoi(s1);
	printf("%d", n);

	return 0;
}
