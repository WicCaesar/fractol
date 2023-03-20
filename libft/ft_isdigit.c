/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:24:10 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/25 22:06:43 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		return (0);
	return (1);
}

// If the value is larger than a type int, returns 1.
int	ft_isoutofintrange(char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		if (ft_atolli(values[i]) > INT_MAX || ft_atolli(values[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnumeric(const char *str)
{
	int			length;
	static int	i;
	static int	operator_count;
	static int	separator_count;

	length = ft_strlen(str);
	while (i < length)
	{
		if (str[i] == '.' || str[i] == ',')
		{
			separator_count++;
			if (separator_count > 1)
				return (0);
		}
		if (str[i] == '-' || str[i] == '+')
		{
			operator_count++;
			if (operator_count > 1 || (i != 0 && str[i - 1] != 'e'))
				return (0);
		}
		else if (!ft_isdigit(str[i]) && str[i] != 'e')
			return (0);
		i++;
	}
	return (1);
}
