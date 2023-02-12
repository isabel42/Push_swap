/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/12 23:06:36 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

int	ft_lst_i(t_list *lst_a, int i)
{
	int		count;
	t_list	*first;

	count = 0;
	first = lst_a;
	while (first->next)
	{
		if (((first->content > i && i > first->next->content)
				|| (first->content < i && count == 0
					&& ft_lstsorted_srev(first) == 1))
			|| ((first->content < i && i < first->next->content)
				|| (first->content > i && count == 0
					&& ft_lstsorted_s(first) == 1)))
			break ;
		count++;
		first = first->next;
	}
	return (count);
}

int	ft_lstbreak(t_list *lst_a)
{
	int		count;
	int		prev_content;
	t_list	*first;

	count = 0;
	first = lst_a;
	prev_content = ft_lstlast(lst_a)->content;
	while (first->next)
	{
		if (prev_content > first->content)
			break ;
		count++;
		first = first->next;
	}
	return (count);
}

void	ft_mintotop(t_list **lst_a)
{
	t_list	*last;
	int		count;
	int		size;

	count = ft_lstbreak(*lst_a);
	size = ft_lstsize(*lst_a);
	last = ft_lstlast(*lst_a);
	if (2 * count < size)
	{
		while (last->content < (*lst_a)->content)
		{
			r(lst_a);
			printf("ra\n");
			last = ft_lstlast(*lst_a);
		}
	}
	else
	{
		while (last->content < (*lst_a)->content)
		{
			rr(lst_a);
			printf("rra\n");
			last = ft_lstlast(*lst_a);
		}
	}
}

void	ft_itotop(t_list **lst_a, int i)
{
	int		count;
	int		size;
	int		j;

	count = ft_lst_i(*lst_a, i);
	size = ft_lstsize(*lst_a);
	j = 1;
	if (2 * count < size)
	{
		while (j < count)
		{
			r(lst_a);
			printf("ra\n");
			j++;
		}
	}
	else
	{
		while (j < count)
		{
			rr(lst_a);
			printf("rra\n");
			j++;
		}
	}
}
