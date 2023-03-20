/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:44:15 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/25 22:21:20 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_leadingzeroes(char **values);
int		ft_isnodeduplicate(t_stack *stack);
int		ft_setindex(const char *s1, const char *s2);
void	ft_error(t_stack **stack);

// Parsing a string of characters is analysing the syntax of this string to find
// tokens, or items, and then create a structure from the result.

// Leading zeroes are redundant, so they are removed. If the string is empty
// after removing the zeroes, it is replaced by "0".
void	ft_leadingzeroes(char **values)
{
	int	i;
	int	j;

	i = 0;
	while (values[i])
	{
		j = 0;
		while (values[i][j])
		{
			if (values[i][j] == '+' || values[i][j] == '-')
				j++;
			else if (values[i][j] == '0')
				j++;
			else if (values[i][j] == '\0')
				values[i] = "0";
			else
				j++;
		}
		i++;
	}
}

// Duplicates are not allowed. The function returns 1 if there are duplicates.
int	ft_isnodeduplicate(t_stack *stack)
{
	t_stack	*element;
	t_stack	*comparison;

	element = stack;
	while (element)
	{
		comparison = element->next;
		while (comparison)
		{
			if (element->value == comparison->value)
				return (1);
			comparison = comparison->next;
		}
		element = element->next;
	}
	return (0);
}

// Sets the index to the first relevant digit (not a plus sign or leading zero).
int	ft_setindex(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	if (s1[index] == '+')
	{
		if (s2[0] != '+')
			index++;
	}
	while (s1[index] == '0')
		index++;
	return (index);
}

// Just for saving lines.
void	ft_error(t_stack **stack)
{
	if (stack == NULL || *stack != NULL)
		ft_stackclear(stack, free);
	write(2, "Error\n", 6);
	exit (0);
}
