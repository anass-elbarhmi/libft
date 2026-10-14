#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	unsigned char p[n];

	if ((dest == NULL) && (src == NULL))
	{
		return (NULL);
	}
	
	i = 0;
	while (i < n)
	{
		p[i] = ((unsigned char *)src)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = p[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	size_t i = 0;
	//char *p = NULL;
	char dest[] = "wwwwwwww";
	char src[] = "bbbbb";
	//ft_memcpy(dest, src, 10);
	memcpy(dest, src, 2);
	while (dest[i])
	{
		printf("%c",dest[i]);
		i++;
	}
	printf("\n");
	return 0;
}