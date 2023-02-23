/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/23 18:37:54 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

void	ft_free_pp_int(int **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i][j])
		{
			s[i][j] = 0;
			j++;
		}
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_free_lst(t_list *lst)
{
	while (lst)
	{
		lst->content = 0;
		free(lst);
		lst = lst->next;
	}
}

void	ft_free_lst_char(t_listc *lst)
{
	while (lst)
	{
		free(lst);
		lst = lst->next;
	}
}

void	ft_ps_exit(t_list **lst_a, t_listc **sol)
{
	int size_lst;

	size_lst = ft_lstsize(*lst_a);
	ft_tocount_a(lst_a, ft_lstbreak(*lst_a), sol);
	ft_free_lst(*lst_a);
	ft_optisol(sol, size_lst);
	//ft_printlst_char(*sol);
	printf("size of sol: %d", ft_lstsize_char(*sol));
	ft_free_lst_char(*sol);
	exit(0);
}
