/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/15 16:26:29 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

void	ft_tocount_a(t_list **lst_a, int count, r_list **sol)
{
	int	size;
	int	j;
	size = ft_lstsize(*lst_a);
	j = 0;
	if (2 * count < size)
	{
		while (j < count)
		{
			ra(lst_a, sol);
			j++;
		}
	}
	else
	{
		while (j < size - count)
		{
			rra(lst_a, sol);
			j++;
		}
	}
}

void	ft_tocount_b(t_list **lst_a, int count, r_list **sol)
{
	int	size;
	int	j;

	size = ft_lstsize(*lst_a);
	j = 0;
	if (2 * count < size)
	{
		while (j < count)
		{
			rb(lst_a, sol);
			j++;
		}
	}
	else
	{
		while (j < size - count)
		{
			rrb(lst_a, sol);
			j++;
		}
	}
}

void	ft_lstadd_back_char(r_list **lst, r_list *new)
{
	r_list	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast_char(*lst);
		last->next = new;
	}
}

r_list	*ft_lstlast_char(r_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize_char(r_list *lst)
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