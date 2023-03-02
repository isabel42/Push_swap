/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_issorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/03/02 12:58:21 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

int	ft_lstsorted(t_list *lst)
{
	int	i;
	int	b;
	int	last;
	int	first;

	i = 0;
	b = 0;
	first = lst->content;
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			b++;
		lst = lst->next;
		i++;
	}
	last = ft_lstlast(lst)->content;
	if (first < last)
			b++;
	if (b > 1)
		return (0);
	return (1);
}

int	ft_lstsorted_rev(t_list *lst)
{
	int	i;
	int	b;
	int	last;
	int	first;

	i = 0;
	b = 0;
	first = lst->content;
	while (lst->next)
	{
		if (lst->content < lst->next->content)
			b++;
		lst = lst->next;
		i++;
	}
	last = ft_lstlast(lst)->content;
	if (first > last)
			b++;
	if (b > 1)
		return (0);
	return (1);
}

int	ft_lstsorted_s(t_list *lst)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			b++;
		lst = lst->next;
		i++;
	}
	if (b > 0)
		return (0);
	return (1);
}

int	ft_lstsorted_srev(t_list *lst)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (lst->next)
	{
		if (lst->content < lst->next->content)
			b++;
		lst = lst->next;
		i++;
	}
	if (b > 0)
		return (0);
	return (1);
}
