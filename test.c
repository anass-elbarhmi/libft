#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && s1[i] && s2 [i])
	{
		if (((const unsigned char *)s1)[i] != ((const unsigned char *)s2)[i])
		{
			return (((const unsigned char *)s1)[i]-((const unsigned char *)s2)[i]);
		}
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (((const unsigned char *)s1)[i]-((const unsigned char *)s2)[i]);
}

int	main(void)
{	
	char s1[]="abc";
	char s2[]="abcde";
	
	printf("%d",ft_strncmp(s1,s2,4));
	
	return (0);
}