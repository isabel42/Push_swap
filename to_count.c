/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/16 15:45:59 by itovar-n         ###   ########.fr       */
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
