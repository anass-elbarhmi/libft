/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>

char *ft_substr(char const *s, unsigned int start,size_t len)
{
	char *new;
	size_t i;
	size_t new_len;

	i = 0;
	if (!s)
	{
		return NULL;
	}
	if (start >= ft_strlen(s))
	{
		len = 0;
	}
	else if (len > (ft_strlen(s) - start));
	{
		len = ft_strlen(s) - start;
	}
	new = (char *)malloc(len + 1);
	if (!new)
		return NULL;
	while (i < len && s[start])
	{
		new[i] = s[start];
		i++;
	}
	new[i] = '\0';

	return new;
	
	
	
}

int main(void)
{
	char buf[8];

	my_memset(buf, 'h', 1);
	my_memset(buf+1, 'e', 1);
	my_memset(buf+2, 'l', 1);
	my_memset(buf+3, 'o', 1);
	my_memset(buf+4, 0, 1);
	printf("%s", buf);
}
