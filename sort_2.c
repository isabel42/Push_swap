/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/03/02 12:34:00 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

void	ft_sort(t_list **lst_a, t_list **lst_b, int value_max, t_listc **sol)
{
	int	i;
	int	j;

	i = 1;
	ft_chek_three_sorted(lst_a, lst_b, value_max, sol);
	while (ft_lstsorted(*lst_a) == 0)
	{
		if (i > 1)
			ft_totroube(lst_a, sol);
		j = 1;
		while (j <= i && ft_lstsorted(*lst_a) == 0)
		{
			if (ft_lstsize(*lst_a) < value_max)
				value_max = ft_lstsize(*lst_a);
			ft_ns_tob(lst_a, lst_b, value_max, sol);
			ft_chek_three_sorted(lst_a, lst_b, value_max, sol);
			if (i > 1)
				ft_s_tob(lst_a, lst_b, j * value_max, sol);
			ft_chek_three_sorted(lst_a, lst_b, value_max, sol);
			j++;
		}
		ft_btoa_s(lst_a, lst_b, sol, ft_lstsize(*lst_b));
		i++;
	}
	ft_ps_exit(lst_a, sol);
}

void	ft_chek_three_sorted(t_list **lst_a,
			t_list **lst_b, int value_max, t_listc **sol)
{
	if (ft_lstsize(*lst_a) == 3 && ft_lstsorted(*lst_a) == 0)
		sa(lst_a, sol);
	if (ft_lstsorted(*lst_a) == 1)
	{
		ft_btoa_s(lst_a, lst_b, sol, value_max);
		ft_ps_exit(lst_a, sol);
	}
}
