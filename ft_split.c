#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int is_sep(char ch,char sep)
{
	if (ch == sep)
	{
		return 1;
	}
	return 0;
}
static size_t ft_count_words(char const *s,char sep)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!is_sep(s[i],sep))
		{
			count++;
		}
		while (s[i] && !is_sep(s[i],sep))
		{
			i++;
		}
		while (s[i] && is_sep(s[i],sep))
		{
			i++;
		}
	}
	return count;
}

char **ft_split(char const *s, char c)
{
	size_t i;
	size_t count_words;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		
	}
	
}
int main()
{
	char s[] = "an....an. aasd.ddddd.";
	printf("%d",(int)ft_count_words(s,'.'));
}
