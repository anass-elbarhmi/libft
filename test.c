/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

size_t my_strlcpy(char *dst, char const *src, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
	{
		return ft_strlen(src);
	}
	while (i < (n - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ft_strlen(src);
}
size_t my_strlcat(char *dest, char const *src, size_t size)
{
	size_t dest_len;
	size_t src_len;
	size_t i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
	{
		return src_len;
	}
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	while ((i + dest_len) < (size - 1) && src[i])
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (src_len + dest_len);
}

int main(void)
{
	char s[20] = "abcdef";
	char s2[] = "anassssssd";
	// char dest[] = "elbarhmi" ;

	my_strlcat(s, s2, 15);
	printf("%s", s);

	return 0;
}
