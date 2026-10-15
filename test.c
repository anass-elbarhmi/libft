#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	

	if ((dest == NULL) && (src == NULL))
	{
		return (NULL);
	}
	if (n == 0)
	{
		return dest;
	}
	
	if (dest <= src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)dest)[i];
			i++;
		}
	}
	else
	{	i = n-1;
		while (i > 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	}
	return (dest);
}

int	main(void)
{	
	char *dest;
	char *src;

	src = malloc(sizeof(char)*6);
	dest = src + 2;

	strcpy(src, "abcde");
	ft_memmove(dest, src, 5);

	printf("%s",dest);
	
	return (0);
}