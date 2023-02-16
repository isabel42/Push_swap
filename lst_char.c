/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/16 13:20:42 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

void	ft_lstadd_back_char(t_listc **lst, t_listc *new)
{
	t_listc	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast_char(*lst);
		last->next = new;
	}
}

t_listc	*ft_lstlast_char(t_listc *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize_char(t_listc *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_printlst_char(t_listc *sol)
{
	while (sol)
	{
		ft_putstr_fd(sol->content, 1);
		sol = sol->next;
	}
}
