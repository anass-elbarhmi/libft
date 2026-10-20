#include "libft.h"
#include <stdlib.h>

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);

	while (i < len)
	{
		f(i,&s[i]);
		i++;
	}
}