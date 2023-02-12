/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/12 20:35:22 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

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
		if (i == best [j])
		{
			r(lst_a);
			j++;
		}
		else
		{
			p(lst_a, lst_b);
		}
		i++;
	}
	free(best);
}
