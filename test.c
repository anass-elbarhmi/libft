/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

size_t	my_strlcpy(char *dst, char const *src, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
	{
		return ft_strlen(src);
	}
	while (i < (n-1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ft_strlen(src);
}


int main(void)
{
	char s[20] = "abcdef";
	char s2[] = "anassssssd";
	//char dest[] = "elbarhmi" ;

	my_strlcpy(s,s2,8);
	printf("%s",s);

	return 0;
}
