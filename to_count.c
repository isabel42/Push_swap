/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/24 16:57:18 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

void	ft_tocount_a(t_list **lst_a, int count, t_listc **sol)
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

void	ft_tocount_b(t_list **lst_b, int count, t_listc **sol)
{
	int	size;
	int	j;

	size = ft_lstsize(*lst_b);
	j = 0;
	if (2 * count < size)
	{
		while (j < count)
		{
			rb(lst_b, sol);
			j++;
		}
	}
	else
	{
		while (j < size - count)
		{
			rrb(lst_b, sol);
			j++;
		}
	}
}

void ft_totroube(t_list **lst_a, t_listc **sol)
{
	if (ft_lstsorted(*lst_a) == 1)
		ft_ps_exit(lst_a, sol);
	ft_tocount_a(lst_a, ft_lsttrouble(*lst_a)-1, sol);
	if ((*lst_a) && (*lst_a)->next && (*lst_a)->next->next && (*lst_a)->content > (*lst_a)->next->content && ((*lst_a)->content < (*lst_a)->next->next->content || ft_lstsorted_s((*lst_a)->next->next) == 1))
		sa(lst_a, sol);
	if (ft_lsttrouble(*lst_a) > 0 && ft_lstsorted(*lst_a) == 0)
		ft_totroube(lst_a, sol);
	if (ft_lstsorted(*lst_a) == 1)
		ft_ps_exit(lst_a, sol);
}
