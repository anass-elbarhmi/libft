/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>


int	main(void)
{	
	int i = -1 ;
	printf("my function :\n");
	while (i < 256)
	{
		printf("%d\n",ft_isalpha(i));
		i++;	
	}
	i = 0;
	printf("real function:\n");
	while (i < 256)
	{
		printf("%d\n",isalpha(i));	
		i++;
	}
	
	return 0;
}
