#include <string.h>

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
		while (i >= 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)dest)[i];
			i--;
		}
		
	}
	return (dest);
}
