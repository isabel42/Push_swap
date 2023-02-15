/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/15 12:48:32 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

void	ft_toconflict(t_list **lst_a)
{
	int	count;

	count = 0;
	while ((*lst_a)->content < (*lst_a)->next->content)
	{
		r(lst_a);
		count++;
	}
	if (count > 0)
		r(lst_a);
}

void	ft_ns_tob(t_list **lst_a, t_list **lst_b, int value_max)
{
	int	i;
	int	j;
	int	*best;

	i = 1;
	j = 0;
	best = ft_longestlist(*lst_a, value_max);
	while (i <= value_max)
	{
		if (best [j] && i == best [j])
		{
			r(lst_a);
			j++;
			i++;
			continue ;
		}
		// ft_itotop(lst_b, (*lst_a)->content);
		ft_tocount(lst_b,(ft_lst_i(*lst_b, (*lst_a)->content)));
		p(lst_a, lst_b);
		if ((ft_lstsize(*lst_b) == 3 && ft_lstsorted(*lst_b) == 1)
			|| (ft_lstsize(*lst_b) == 2 && ft_lstsorted_s(*lst_b) == 1))
			s(lst_b);
		i++;
	}
	free(best);
	ft_tocount(lst_b, ft_lstbreak(*lst_b));
}

void	ft_btoa_s(t_list **lst_a, t_list **lst_b)
{
	int	ref;

	ref = ft_lstlast(*lst_a)->content;
	while (*lst_b)
	{
		if (ref < (*lst_b)->content
			|| (ft_lstsorted_s(*lst_a)
				&& (((*lst_b)->content > ref
						&& (*lst_b)->content > (*lst_a)->content)
					|| ((*lst_b)->content < ref
						&& (*lst_b)->content < (*lst_a)->content))))
			p(lst_b, lst_a);
		else
			rr(lst_a);
		ref = ft_lstlast(*lst_a)->content;
	}
	ft_tocount(lst_a, ft_lstbreak(*lst_a));
}

void	ft_s_tob(t_list **lst_a, t_list **lst_b, int value_max)
{
	while (ft_lstsize(*lst_b) < value_max)
	{
		rr(lst_a);
		ft_tocount(lst_b,(ft_lst_i(*lst_b, (*lst_a)->content)));
		p(lst_a, lst_b);
	}
	ft_tocount(lst_b, ft_lstbreak(*lst_b));
}
