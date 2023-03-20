/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:47:26 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/25 22:15:57 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newnode)
{
	t_list	*penultimate;

	if (!newnode)
		return ;
	if (!*lst)
	{
		*lst = newnode;
		return ;
	}
	penultimate = ft_lstlast(*lst);
	penultimate->next = newnode;
}

void	ft_stackadd_back(t_stack **stack, int value, int index)
{
	t_stack	*newnode;
	t_stack	*penultimate;

	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		exit (1);
	newnode->value = value;
	newnode->index = index;
	newnode->next = NULL;
	if (!*stack)
	{
		*stack = newnode;
		return ;
	}
	penultimate = ft_stacklast(*stack);
	penultimate->next = newnode;
}
