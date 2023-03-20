/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:20:07 by cnascime          #+#    #+#             */
/*   Updated: 2023/03/20 12:37:48 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

int	ft_operator(const char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		return (-1);
	return (1);
}

// Converts a numeric character in a string to an integer by subtracting 0 from
// the corresponding ASCII decimal value to get a valid numerical value, then
// multiplies by 10 to calculate the following digit. It skips spaces and tabs.
int	ft_atoi(const char *str)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	while (ft_isspace(str[i]) || str[i] == '+' || str[i] == '-' || str[i])
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * (ft_operator(str)));
}

long long	ft_atolli(const char *str)
{
	int					i;
	unsigned long long	number;

	i = 0;
	number = 0;
	while (ft_isspace(str[i]) || str[i] == '+' || str[i] == '-' || str[i])
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * (ft_operator(str)));
}

// Calculates the integer and decimal parts of a number separately.
double	ft_atof(const char *str)
{
	int		i;
	double	number;

	i = 0;
	number = (double)ft_atoi(str);
	while (ft_isspace(str[i]) || str[i] == '+' || str[i] == '-' || str[i])
		i++;
	i = i + ft_strlen(ft_itoa((int)number));
	while (str[i] && ft_isdigit(str[i]) && (str[i] != '.' || str[i] != ','))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.' || str[i] == ',')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		number = number + ((str[i] - '0') / 10);
		i++;
	}
	return (number * (ft_operator(str)));
}
// ? Line 86: number = number + ((str[i] - '0') * div); div = div * 0.1; ???
