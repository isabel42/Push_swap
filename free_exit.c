/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/28 16:49:27 by itovar-n         ###   ########.fr       */
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
	t_list	*cp;

	while (lst)
	{
		lst->content = 0;
		cp = lst;
		lst = lst->next;
		free(cp);
	}
}

void	ft_free_lst_char(t_listc *lst)
{
	t_listc	*cp;

	while (lst)
	{
		cp = lst;
		lst = lst->next;
		free(cp);
	}
}

void	ft_ps_exit(t_list **lst_a, t_listc **sol)
{
	ft_tocount_a(lst_a, ft_lstbreak(*lst_a), sol);
	ft_optisol(sol);
	ft_printlst_char(*sol);
	//ft_lstprint(*lst_a);
	printf("\nsize of sol: %d", ft_lstsize_char(*sol));
	ft_free_lst(*lst_a);
	ft_free_lst_char(*sol);
	exit(0);
}
