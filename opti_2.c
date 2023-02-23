/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/23 15:25:04 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

int	ft_opti_countr(t_listc *test, int size_lst)
{
	t_listc *next;
	int i;

	i = 0;
	if(ft_strncmp(test->content, "ra\n", 3) == 0)
	{
		next = test;
		while(next && ft_strncmp(next->content, "ra\n", 3) == 0)
		{
			i++;
			next = next->next;
		}
	}
	if(i > size_lst / 2)
		return (i);
	else
		return (0);
}

int	ft_opti_countrr(t_listc *test, int size_lst)
{
	t_listc *next;
	int i;

	i = 0;
	if(ft_strncmp(test->content, "rra\n", 4) == 0)
	{
		next = test;
		while (next && ft_strncmp(next->content, "rra\n", 4) == 0)
		{
			i++;
			next = next->next;
		}
	}
	if(i > size_lst / 2)
		return (i);
	else
		return (0);
}

void ft_opti_r_rr(t_listc **sol, int size_lst)
{
	t_listc	*test;
	t_listc	*cp;
	int i;

	test = *sol;
	while(test)
	{
		if(ft_opti_countr(test, size_lst) > 0)
		{
			i = size_lst - ft_opti_countr(test, size_lst);
			while (i > 0)
			{
				test->content = "rra\n";
				i--;
				if(i > 0)
					test = test->next;
			}
			while (test->next && ft_strncmp(test->next->content, "ra\n", 3) == 0)
			{
				cp = test->next->next;
				free(test->next);
				test->next = cp;
				if (ft_strncmp(test->next->content, "ra\n", 3) != 0)
					test = test->next;
			}
		}
		test = test->next;	
	}
}

void	ft_optisol(t_listc **sol, int size_lst)
{
	if (*sol)
	{
		ft_optisol_rp(sol);
		ft_opti_r_rr(sol, size_lst);
		ft_optisol_ss(sol);
		ft_optisol_rr(sol);
		ft_optisol_rrr(sol);
		printf("%d\n", size_lst);
	}
}
