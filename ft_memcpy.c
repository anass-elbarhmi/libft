#include <string.h>

void *memcpy(void *dest, const void *src, size_t n)
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