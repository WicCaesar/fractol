/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 05:30:33 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/08 19:05:26 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates and returns a new string which is the concatenation of s1 and s2.
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*superbonder;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	superbonder = malloc(1 * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!superbonder)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			superbonder[i] = s1[i];
	while (s2[j] != '\0')
		superbonder[i++] = s2[j++];
	superbonder[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (superbonder);
}
