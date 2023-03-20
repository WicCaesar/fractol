/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:05:19 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/25 22:16:31 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Takes a node, erases the node’s content using the function del
// and frees the node. next must not be freed.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_stackdelone(t_stack *stack, void (*del)(void *))
{
	if (!stack || !del)
		return ;
	del((void *)&stack->value);
}
