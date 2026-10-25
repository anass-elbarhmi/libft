/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char *s  = "anass";
	int len;

	len = ft_strlen(s);
	printf("len : %d",len);
	ft_putstr_fd(s, 1);
}
