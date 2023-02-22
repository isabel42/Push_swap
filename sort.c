/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/22 15:28:47 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

void	ft_sort_three(t_list **lst_a, t_listc **sol)
{
	sa(lst_a, sol);
	ft_tocount_a(lst_a, ft_lstbreak(*lst_a), sol);
}

void	ft_ns_tob(t_list **lst_a, t_list **lst_b, int v_m, t_listc **sol)
{
	int	i;
	int	j;
	int	*best;

	i = 1;
	j = 0;
	best = ft_longestlist(*lst_a, v_m);
	while (i <= v_m)
	{
		if (best [j] && i == best[j])
		{
			ra(lst_a, sol);
			j++;
			i++;
			continue ;
		}
		ft_tocount_b(lst_b, (ft_lst_i(*lst_b, (*lst_a)->content)), sol);
		pa(lst_a, lst_b, sol);
		if ((ft_lstsize(*lst_b) == 3 && ft_lstsorted(*lst_b) == 1)
			|| (ft_lstsize(*lst_b) == 2 && ft_lstsorted_s(*lst_b) == 1))
			sb(lst_b, sol);
		i++;
	}
	free(best);
	ft_tocount_b(lst_b, ft_lstbreak(*lst_b), sol);
}

void	ft_btoa_s(t_list **lst_a, t_list **lst_b, t_listc **sol, int v_m)
{
	int	ref;

	ref = ft_lstlast(*lst_a)->content;
	while (*lst_b)
	{	
		if (ft_lstsorted(*lst_a) == 1)
		{
			if ((ft_lstsorted_s(*lst_a) == 0 && (ref < (*lst_b)->content
						&& (*lst_a)->content > (*lst_b)->content))
				|| (((*lst_b)->content > ref
						&& (*lst_b)->content > (*lst_a)->content)
					|| ((*lst_b)->content < ref
						&& (*lst_b)->content < (*lst_a)->content)))
				pb(lst_b, lst_a, sol);
			else if (ft_lstsize(*lst_a) != 2)
				ft_tocount_a(lst_a, ft_lst_i((*lst_a), (*lst_b)->content), sol);
			else
				rra(lst_a, sol);
		}
		else if ((*lst_b)->content > ft_lstmax(*lst_a))
			pb(lst_b, lst_a, sol);
		else if (ref > (*lst_b)->content
			&& (ref < (*lst_a)->content || ft_lstsize(*lst_b) == v_m))
			rra(lst_a, sol);
		else
			pb(lst_b, lst_a, sol);
		ref = ft_lstlast(*lst_a)->content;
	}
}

void	ft_s_tob(t_list **lst_a, t_list **lst_b, int value_max, t_listc **sol)
{
	while (ft_lstsize(*lst_b) < value_max
		|| (ft_lstsize(*lst_a) < 6 && ft_lstsize(*lst_a) > 2))
	{
		rra(lst_a, sol);
		ft_tocount_b(lst_b, (ft_lst_i(*lst_b, (*lst_a)->content)), sol);
		pa(lst_a, lst_b, sol);
	}
	ft_tocount_b(lst_b, ft_lstbreak(*lst_b), sol);
	if (ft_lstsize(*lst_a) == 3)
		ft_sort_three(lst_a, sol);
}

void	ft_sort(t_list **lst_a, t_list **lst_b, int value_max, t_listc **sol)
{
	if (ft_lstsorted(*lst_a) == 1)
	{
		ft_ps_exit(lst_a, sol);
	}
	if (ft_lstsize(*lst_a) == 3)
	{	
		ft_sort_three(lst_a, sol);
		ft_ps_exit(lst_a, sol);
	}
	if (ft_lstsize(*lst_a) > value_max)
	{
		ft_tocount_a(lst_a, ft_lsttrouble(*lst_a), sol);
	}
	ft_ns_tob(lst_a, lst_b, value_max, sol);
	if (ft_lstsorted(*lst_a) == 1)
	{	
		ft_btoa_s(lst_a, lst_b, sol, value_max);
		ft_ps_exit(lst_a, sol);
	}
	else
	{	
		ft_s_tob(lst_a, lst_b, value_max, sol);
		ft_btoa_s(lst_a, lst_b, sol, value_max);
		ft_sort(lst_a, lst_b, value_max, sol);
	}
}
