/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:10:29 by aoqdeh            #+#    #+#             */
/*   Updated: 2025/08/21 18:26:05 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ch;
	int		i;

	ch = (char) c;
	str = (char *) s;
	i = 0;
	while (str[i])
		i++;
	while (i > 0 && str[i] != ch)
		i--;
	if (str[i] == ch)
		return (&str[i]);
	else
		return (NULL);
}
/*
#include <stdio.h>
int main()
{
	printf("%p \n",ft_strrchr("hello kjfsdkj",'k'));
	printf("%p \n",ft_strrchr("hello kjfsdkj",'\0'));
	printf("%p \n",ft_strrchr("hello kjfsdkj",'j'));
}
*/
