

#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (((unsigned char *)src)[i] &&  i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	size_t i = 0;

	char dest[] = "aaaaaa";
	char src[] = "bbbbbb";
	ft_memcpy(dest, src, 10);
	while (dest[i])
	{
		printf("%c",dest[i]);
		i++;
	}
	return 0;
}