/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/11 19:52:36 by itovar-n         ###   ########.fr       */
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

int	*ft_longestlist(t_list *lst, int value_max)
{
	int		j;
	int		**table;
	int		combi;
	int		*sol;

	j = value_max + 1;
	while (j--)
	{	
		combi = ft_fact(value_max) / (ft_fact(j) * ft_fact(value_max - j));
		table = ft_combi(value_max, j);
		sol = ft_longestlist_bis(combi, table, lst, value_max);
		if(sol != NULL)
		{ 
			ft_free_pp_int(table);
			return (sol);
		}
	}
	ft_free_pp_int(table);
	return (ft_calloc(j + 1, sizeof(*table)));
}

int	*ft_longestlist_bis(int combi, int **table, t_list *lst, int value_max)
{
	t_list	*lst_table;
	int i;
	int *sol;

	i = 0;
	while (i < combi)
	{
		lst_table = ft_linetlstbuild(table [i], lst, value_max);
		if (ft_lstsorted_s(lst_table) == 1)
		{
			sol = ft_intcpy(table[i]);
			ft_free_lst(lst_table);
			return (sol);
		}
		ft_free_lst(lst_table);
		i++;
	}
	return(NULL);
}

int	*ft_intcpy(int *table)
{
	int *sol;
	int i;

	i = 0;
	while(table[i] != 0)
		i++;
	sol = ft_calloc(i + 1, sizeof(*table));
	sol[i] =0;
	while (i >= 0)
	{
		sol[i] = table [i];
		i--;
	}
	return (sol);
}
