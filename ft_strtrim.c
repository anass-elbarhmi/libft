#include "libft.h"
#include <stdlib.h>

static int is_in_set(char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return 1;
		}
		i++;
	}
	return 0;
}
static size_t ft_trimmed_len(char const *s1, char const *set)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (s1[i] && is_in_set(s1[i],set))
	{
		len++;
	}
	return len;
}
char *ft_strtrim(char const *s1, char const *set)
{
	size_t len;
	size_t trimed_len;
	size_t i;
	size_t j;
	char *new;
	
	len = ft_strlen(s1);
	trimed_len = ft_trimmed_len(s1, set);
	i = 0;
	j = 0;
	new = (char *)malloc(trimed_len + 1);
	if (!new)
		return NULL;
	while (s1[i])
	{
		if (!is_in_set(s1[i],set))
		{
			new[j] = s1[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return new;
}
int main(void)
{
	char s[] = "";
	char set[] ="";
	printf("%s",ft_strtrim(s,set));
}