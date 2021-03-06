/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 21:40:59 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/12 20:16:03 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *tofree, char *s1, char *s2)
{
	char	*str;
	int		len_join;
	int		i;
	int		i2;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	len_join = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	i2 = 0;
	str = (char *)malloc(sizeof(char) * (len_join + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
		str[i++] = s2[i2++];
	str[i] = '\0';
	ft_strdel(&tofree);
	return (str);
}
