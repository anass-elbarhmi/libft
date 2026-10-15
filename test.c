#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned  char p[n];

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
	char	dest[20] = "wwwwwwwwww";
	char	src[] = "Hello";

	ft_memmove(dest, src, 5);
	printf("%s\n", dest);
	return (0);
}