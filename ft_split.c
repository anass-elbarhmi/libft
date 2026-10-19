/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <ael-barh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:38:13 by ael-barh          #+#    #+#             */
/*   Updated: 2026/10/19 15:01:40 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t ft_count_words(char const *s, char sep)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!(s[i] == sep))
		{
			count++;
		}
		while (s[i] && !(s[i] == sep))
		{
			i++;
		}
		while (s[i] && (s[i] == sep))
		{
			i++;
		}
	}
	return count;
}
static char *ft_free(char **p, size_t i)
{
	while (i > 0)
	{
		free(p[i]);
		i--;
	}
	free(p[i]);
	free(p);
	return NULL;
}

static char **words_alloction(char const *s, char sep, size_t count_words, char **p)
{
	size_t i;
	size_t j;
	size_t word_len;

	word_len = 0;
	i = 0;
	j = 0;
	while (i < count_words)
	{
		word_len = 0;
		while (s[j] && s[j] == sep)
			j++;
		while (s[j] && !(s[j] == sep))
		{
			word_len++;
			j++;
		}
		p[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!p[i])
			ft_free(p, i);
		p[i][word_len] = '\0';
		i++;
	}
	return p;
}
static char **fill_strings(char **p, char const *s, char sep)
{
	size_t i_init;
	size_t i;
	size_t j;

	i_init = 0;
	i = 0;
	j = 0;
	while (p[i_init])
	{
		i = 0;
		while (s[j] && (s[j] == sep))
		{
			j++;
		}
		while (s[j] && !(s[j] == sep))
		{
			p[i_init][i] = s[j];
			i++;
			j++;
		}
		i_init++;
	}
	return p;
}

char **ft_split(char const *s, char sep)
{
	size_t i_init;
	size_t i;
	size_t j;
	size_t count_words;
	char **p;

	count_words = ft_count_words(s, sep);
	i_init = 0;
	i = 0;
	j = 0;
	p = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (!p)
	{
		free(p);
		return NULL;
	}
	p[count_words] = NULL;
	p = words_alloction(s, sep, count_words, p);
	if (!p)
		return NULL;
	p = fill_strings(p, s, sep);
	return p;
}
int main()
{
	char s[] = ".adnnqnj.cmkkam...akmkca cas";
	char **p;
	int i = 0;
	p = ft_split(s, '.');

	while (p[i])
	{
		printf("%s\n", p[i]);
		i++;
	}
}
