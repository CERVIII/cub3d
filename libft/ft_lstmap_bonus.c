/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:37:35 by pcervill          #+#    #+#             */
/*   Updated: 2022/04/18 11:31:59 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*lstcp;
	void	*lstcont;

	if (!lst)
		return (NULL);
	lstcp = NULL;
	while (lst)
	{
		lstcont = (*f)(lst->content);
		if (lstcont)
		{
			new = ft_lstnew(lstcont);
			if (!new)
			{
				del(lstcont);
				ft_lstclear(&lstcp, del);
				return (NULL);
			}
			ft_lstadd_back(&lstcp, new);
			lst = lst -> next;
		}
	}
	return (lstcp);
}
