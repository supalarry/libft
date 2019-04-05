/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 16:31:56 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/18 16:31:58 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_counter(char const *s, char c)
{
	int		state;
	int		count;
	size_t	i;

	state = 0;
	count = 0;
	i = 0;
	while (s[i] != '\0' && s != NULL)
	{
		if (s[i] != c && state == 0)
		{
			count++;
			state = 1;
		}
		if (s[i] == c)
		{
			state = 0;
		}
		i++;
	}
	return (count);
}

static void		ft_values(char const *s, char c, char **database)
{
	int		state;
	int		count;
	size_t	i;

	state = 0;
	count = 0;
	i = 0;
	while (s[i] != '\0' && database != NULL)
	{
		if (s[i] != c && state == 0)
		{
			database[count] = (char *)(s + i);
			count++;
			state = 1;
		}
		if (s[i] == c)
		{
			state = 0;
		}
		i++;
	}
	if (database != NULL)
	{
		database[count] = 0;
	}
}

static char		**ft_database(char const *s, char c)
{
	int		i;
	int		j;
	char	*word;
	char	**database;

	i = -1;
	j = 0;
	database = (char **)malloc((ft_counter(s, c) + 1) * sizeof(char *));
	ft_values(s, c, database);
	while (database != NULL && ++i < ft_counter(s, c) && ft_counter(s, c) != 0)
	{
		while (database[i][j] != c && database[i][j] != '\0')
			j++;
		word = (char *)malloc(j + 1);
		j = 0;
		while (database[i][j] != c && database[i][j] != '\0')
		{
			word[j] = database[i][j];
			j++;
		}
		word[j] = '\0';
		database[i] = word;
		j = 0;
	}
	return (database);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**database;

	database = NULL;
	if (s != NULL)
	{
		database = ft_database(s, c);
	}
	return (database);
}
