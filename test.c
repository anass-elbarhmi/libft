/* main.c */
#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char s1[]="zzzanasszzzz";
	char s2[]="anass";
	char *new;

	new = ft_strnstr(s1, s2, 5);
	printf("%s",new);
	return (0);
}