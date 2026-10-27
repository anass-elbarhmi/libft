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

	i = 0;
	if (!s)
	{
		return NULL;
	}
	if (start >= ft_strlen(s))
	{
		len = 0;
	}
	else if (len > (ft_strlen(s) - start))
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
		start++;
	}
	new[i] = '\0';

	return new;

}

int main(void)
{
	char *s = NULL;
	char *sub;
	sub = ft_substr(s, 3, 3);
	printf("%s",sub);
}
