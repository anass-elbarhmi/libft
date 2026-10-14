#include <string.h>

void *memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	unsigned char p[n];

	i = 0;
	while (((unsigned char *)src)[i] &&  i < n)
	{
		p[i] = ((unsigned char *)src)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = p[i];
	}
	
	return (dest);
}