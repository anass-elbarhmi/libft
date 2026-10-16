#include "libft.h"

 char *ft_strdup(const char *s)
 {
	size_t i;
	size_t s_len;
	char *ptr;

	i = 0;
	s_len = ft_strlen(s);
	ptr = (char *)malloc(s_len+1);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';

	return ptr;
 }