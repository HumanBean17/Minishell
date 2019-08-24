#include "minishell.h"

static int		word_count(const char *str)
{
	int	words;
	int	i;
	int	j;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		j = i;
		while (str[j] == ' ' || str[j] == '\t' || str[j] == '\r')
			j++;
		i = j;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\r'
		&& str[i] != '\0')
			i++;
		i--;
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\r'
		&& str[i] != '\0')
			words++;
		i++;
	}
	return (words);
}

static int		skip_tabs(const char *str, int i)
{
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\r') &&
	str[i] != '\0')
		i++;
	return (i);
}

static int		skip_letter(const char *str, int i)
{
	int k;

	k = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\r' &&
	str[i] != '\0')
	{
		k++;
		i++;
	}
	return (k);
}

char			**split_whitespaces(char const *s)
{
	char	**k;
	int		i;
	int		j;
	int		l;

	if (!s)
		return (NULL);
	i = 0;
	l = 0;
	k = (char **)malloc(sizeof(char *) * (1 + word_count(s)));
	if (!k)
		return (NULL);
	while (s[i] != '\0')
	{
		i = skip_tabs(s, i);
		j = skip_letter(s, i);
		if (j == 0)
			break ;
		if (!(k[l++] = ft_strsub(s, i, j)))
			return (NULL);
		i += j;
	}
	if (word_count(s) == 0)
		ft_strdel(&k[0]);
	k[word_count(s)] = NULL;
	return (k);
}
