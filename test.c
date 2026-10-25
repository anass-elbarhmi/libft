/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

void my_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}

}

int main(void)
{
	char s[] = "an";
	my_memset(s, '1', 3);
	printf("%s",s);

	return 0;
}
