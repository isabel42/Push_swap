/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/11 15:43:32 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"


t_list	*ft_linetlstbuild(int *combi, t_list *lst, int value_max)
{
	t_list	*new;
	t_list	*second;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = NULL;
	while (i < value_max)
	{
		if (combi[j] == i + 1 && !new)
		{
			new = ft_lstnew(lst->content);
			j++;
		}
		else if (combi[j] == i + 1)
		{
			second = ft_lstnew(lst->content);
			ft_lstadd_back(&new, second);
			j++;
		}
		lst = lst->next;
		i++;
	}
	return (new);
}

int *ft_longestlist(t_list *lst, int value_max)
{
	int	i;
	int j;
	int **table;
	t_list *lst_table;

	j = value_max;
	while (j > 0)
	{	
		table = ft_combi(value_max, j);
		i = 0;
		while (table [i][0] > 0)
		{
			lst_table = ft_linetlstbuild(table [i], lst, value_max);
			if(ft_lstsorted_s(lst_table) == 1)
			{
				// ft_free_lst(lst_table);
				// ft_free_pp_int(table);
				return (table [i]);
			}
			// ft_free_pp_int(table);
			// ft_free_lst(lst_table);
			i++;
		}
		j--;
	}
	return(0);
}
