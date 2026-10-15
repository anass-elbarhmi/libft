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
//kkkkkkk
int	main(void)
{	
	char	dest[20] = "www";
	char	src[6] = "Hel\0lo";
	int i = 0;

	ft_memmove(dest, src, 5);
	//write(1,&dest[4],1);
	while (i < 5)
	{
		write(1,&dest[i],1);
		
		i++;
	}
	return (0);
}