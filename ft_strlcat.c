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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dst_len;
	size_t init_dst_len;
	size_t src_len;

	dst_len = ft_strlen(dst);
	init_dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
	{
		return src_len;
	}
	if (size <= init_dst_len)
	{
		return (size + src_len);
	}
	while ((dst_len < size-1) && src[i])
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	
	return (init_dst_len + src_len);
}