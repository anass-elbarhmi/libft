#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t src_len;
	size_t dest_len;

	i = 0;
	src_len = ft_strlen(src);
	while ((i < size-1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] == '\0';

	return src_len;
}