/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:05:31 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/25 22:16:18 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes and frees a given node and every successor of that node, 
// using del and free. Finally, the pointer to the list must be set to NULL.
void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (!del || !list)
		return ;
	current = *list;
	while (current != NULL)
	{
		temp = current->next;
		ft_lstdelone(current, del);
		current = temp;
	}
	*list = NULL;
}

void	ft_stackclear(t_stack **stack, void (*del)(void *))
{
	t_stack	*current;
	t_stack	*temp;

	if (!del || !stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		temp = current->next;
		ft_stackdelone(current, del);
		current = temp;
	}
	*stack = NULL;
}

void	ft_matrixclear(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
