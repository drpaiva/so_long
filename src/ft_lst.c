/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 10:56:04 by dramos-p          #+#    #+#             */
/*   Updated: 2022/01/15 17:04:10 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_dataimg	*ft_lstnew_md(void *content, char opt)
{
	t_dataimg	*elem;

	elem = (t_dataimg *)malloc(sizeof(t_dataimg));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->opt = opt;
	elem->x = 64;
	elem->y = 64;
	elem->next = NULL;
	return (elem);
}

t_dataimg	*ft_lstlast_md(t_dataimg *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstdelone_md(t_dataimg *lst, void (*del)(void*))
{
	if (lst != NULL || del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}

void	ft_lstclear_md(t_dataimg **lst, void (*del)(void*))
{
	t_dataimg	*nlst;
	t_dataimg	*next;

	nlst = *lst;
	while (nlst)
	{
		next = nlst->next;
		ft_lstdelone_md(nlst, del);
		nlst = next;
	}
	*lst = NULL;
}

void	ft_lstadd_back_md(t_dataimg **lst, t_dataimg *new)
{
	t_dataimg	*p;

	if (*lst)
	{
		p = ft_lstlast_md(*lst);
		p->next = new;
	}
	else
		*lst = new;
}