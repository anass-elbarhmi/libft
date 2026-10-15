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

char *ft_strrchr(const char *s, int c)
{
	size_t s_len;

	s_len = ft_strlen(s);
	while (s_len > 0)
	{
		if (s[s_len] == (char)c)
		{
			return ((char *)(s+s_len));
		}
		s_len--;
	}
	if (s[s_len] == (char)c)
	{
		return ((char *)(s+s_len));
	}
	return (NULL);
}