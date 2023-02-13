/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/13 17:09:51 by itovar-n         ###   ########.fr       */
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
	if (lst_a)
	{
		if ((ft_lstsorted_srev(first) == 1 && (ft_lstlast(first)->content > i
					&& first->content < i))
			|| (ft_lstsorted_s(first) == 1 && (ft_lstlast(first)->content < i
					&& first->content > i)))
			return (0);
		while (lst_a->next)
		{
			if (ft_lst_i_bis(lst_a, i, count, first) == 1)
			{
				count++;
				break ;
			}
			count++;
			lst_a = lst_a->next;
		}
	}
	return (count);
}

int	ft_lst_i_bis(t_list *lst_a, int i, int count, t_list *first)
{
	if ((ft_lstsorted_rev(first) == 1
			&& ((lst_a->content > i && lst_a->next->content < i)
				|| (count == ft_lstbreak(first) - 1 && count != 0
					&& ((lst_a->content > i && lst_a->next->content > i)
						|| (lst_a->content < i && lst_a->next->content < i)))))
		|| (ft_lstsorted(first) == 1
			&& ((lst_a->content < i && lst_a->next->content > i)
				|| (count == ft_lstbreak(first) - 1 && count != 0
					&& ((lst_a->content < i && lst_a->next->content < i)
						|| (lst_a->content > i && lst_a->next->content > i))))))
		return (1);
	return (0);
}

int	ft_lstbreak(t_list *lst_a)
{
	int		count;
	t_list	*first;

	count = 0;
	first = lst_a;
	if (ft_lstsorted_s(first) == 1 || ft_lstsorted_srev(first) == 1)
		return (0);
	while (lst_a->next)
	{
		if ((ft_lstsorted(first) == 1 && lst_a->content > lst_a->next->content)
			|| (ft_lstsorted_rev(first) == 1
				&& lst_a->content < lst_a->next->content))
		{
			count++;
			break ;
		}
		count++;
		lst_a = lst_a->next;
	}
	return (count);
}

void	ft_breaktotop(t_list **lst_a)
{
	int	count;
	int	size;
	int	j;

	count = ft_lstbreak(*lst_a);
	size = ft_lstsize(*lst_a);
	j = 0;
	if (2 * count < size)
	{
		while (j < count)
		{
			r(lst_a);
			j++;
		}
	}
	else
	{
		while (j < size - count)
		{
			rr(lst_a);
			j++;
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
	j = 0;
	if (2 * count < size)
	{
		while (j < count)
		{
			r(lst_a);
			j++;
		}
	}
	else
	{
		while (j < size - count)
		{
			rr(lst_a);
			j++;
		}
	}
}
