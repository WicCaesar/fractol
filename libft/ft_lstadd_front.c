/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:02:25 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/25 22:16:06 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *newnode)
{
	if (!lst || !newnode)
		return ;
	newnode->next = *lst;
	*lst = newnode;
}

void	ft_stackadd_front(t_stack **stack, t_stack *newnode)
{
	if (!stack || !newnode)
		return ;
	newnode->next = *stack;
	*stack = newnode;
}
