#include "libft.h"

char * strnstr(const char *big, const char *little, size_t len)
{
	size_t init_i;
	size_t i;
	size_t j;

	while (big[init_i])
	{	
		i = init_i;
		j = 0;
		if(big[i] == little[j])
		{
			while (big[i] == little[j] && j < len)
			{
				i++;
				j++;
			}
			if(little[j] == '\0')
			{
				return (char *)(big + init_i);
			}
		}
	}
	return (NULL);
}