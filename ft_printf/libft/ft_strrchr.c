/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:32:56 by afont             #+#    #+#             */
/*   Updated: 2022/11/23 15:40:24 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	c %= 128;
	i = ft_strlen((char *)s);
	if (s[i] == c)
		return ((char *)s + i);
	while (i--)
		if (s[i] == c)
			return ((char *)s + i);
	return (0);
}
/*
int main()
{
	char s[] = "bonjour";
	printf("%s", ft_strrchr(s, '\0'));
}*/
