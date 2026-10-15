#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - ('a'-'A');
	}
	return (c);
}

int	main(void)
{	
	int c = 'a';
	c = ft_toupper(c);
	printf("%c",c);
	
	return (0);
}