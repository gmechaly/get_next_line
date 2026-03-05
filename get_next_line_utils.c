/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:09:17 by gmechaly          #+#    #+#             */
/*   Updated: 2024/09/02 19:28:41 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	a = c;
	i = 0;
	while (s[i] && s[i] != a)
		i++;
	if (a != '\0' && i == ft_strlen(s))
		return (NULL);
	else
		return ((char *)&s[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (free(s1), NULL);
	while (s1 != NULL && s1[i])
		dst[j++] = s1[i++];
	i = 0;
	free (s1);
	while (s2 != NULL && s2[i])
		dst[j++] = s2[i++];
	dst[j] = '\0';
	return (dst);
}

int	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
