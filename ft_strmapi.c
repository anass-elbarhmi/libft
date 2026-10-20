#include "libft.h"
#include <stdlib.h> 

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int i;
	int len;
	char *p;

	i = 0;
	len = ft_strlen(s);
	p = (char *)malloc(len+1);
	if (!p)
		return NULL;
	while (i < len)
	{
		p[i] = f(i,s[i]);
		i++;
	}
	p[i] = '\0';
	return p;
}
int main(void)
{
	
}