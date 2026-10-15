#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return (char *)(s+i);
		}
		i++;
	}
	if (s[i] == c)
	{
		return (char *)(s+i);
	}
	return (NULL);
}


int	main(void)
{	
	char s[]="abcef";
	char *new;
	

	new = ft_strchr(s,'a');
	printf("%s",new);
	
	return (0);
}