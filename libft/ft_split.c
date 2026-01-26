/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:09:00 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/09/08 16:43:49 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	my_count(char const *s, char c)
{
	int	st;
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		st = i;
		while (s[i] != c && s[i])
			i++;
		if (st < i)
			cnt++;
		else
			i++;
	}
	return (cnt);
}

static char	*my_cpy(char const *s, int st, int en)
{
	char	*tmp;
	int		i;

	tmp = malloc(en - st + 1);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (st < en)
	{
		tmp[i] = s[st];
		i++;
		st++;
	}
	tmp[i] = 0;
	return (tmp);
}

void	free_me_from_agony(char **spltd)
{
	int	i;

	i = 0;
	while (spltd[i])
	{
		free(spltd[i]);
		i++;
	}
	free(spltd);
}

char	**ft_split(char const *s, char c)
{
	char	**spltd;
	int		i;
	int		j;
	int		st;

	spltd = malloc(sizeof(char *) * (my_count(s, c) + 1));
	i = 0;
	j = 0;
	while (s[j] && spltd)
	{
		st = j;
		while (s[j] && s[j] != c)
			j++;
		if (j > st)
		{
			spltd[i] = my_cpy(s, st, j);
			if (spltd[i++] == NULL)
				return (free_me_from_agony(spltd), NULL);
		}
		else
			j++;
	}
	if (spltd)
		spltd[i] = NULL;
	return (spltd);
}
/*
#include <stdio.h>
int main()
{
	int	i;
	char **sp = ft_split("",'m');
	i = 0;
	printf("%p", sp);
	while (sp[i])
	{
		printf("sentence %d: %s\n",i,sp[i]);
		i++;
	}
}*/
