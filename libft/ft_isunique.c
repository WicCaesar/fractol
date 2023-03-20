/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isunique.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 04:50:31 by cnascime          #+#    #+#             */
/*   Updated: 2022/12/21 05:03:35 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks for duplicates in an array of chars.
// Returns 1 (TRUE) if there are no duplicates, 0 (FALSE) if there are.
int	ft_charisunique(char *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// Check for duplicates in an array of ints.
// Returns 1 (TRUE) if there are no duplicates, 0 (FALSE) if there are.
int	ft_numberisunique(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
