#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


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


int	main(void)
{	
	char s[]="abcaf";
	char *new;
	

	new = ft_strrchr(s,'z');
	printf("%s",new);
	
	return (0);
}