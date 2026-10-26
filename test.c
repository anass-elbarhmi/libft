/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

char *my_strnstr(const char *big, const char *little, size_t len)
{
	size_t i_init;
	size_t i;

	i = 0;
	i_init = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i_init] && i_init < len)
	{
		i = 0;
		if (big[i_init] == little[i])
		{
			while (little[i] && (i_init+i) < len && (big[i_init + i] == little[i]))
			{
				i++;
			}
			if (little[i] == '\0')
			{
				return (char *)(big + i_init);
			}
		}
		i_init++;
	}
	return NULL;
}

int main(void)
{
	char s1[] = "abcdef";
	char s2[] = "cde";
	char *new;
	// char dest[] = "elbarhmi" ;

	new = my_strnstr(s1, s2, 3);
	printf("%s", new);

	return 0;
}
