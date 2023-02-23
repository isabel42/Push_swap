/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/23 16:03:47 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

int	ft_opti_countr(t_listc *test, int size_lst, char *ra)
{
	t_listc *next;
	int i;

	i = 0;
	if(ft_strncmp(test->content, ra, 3) == 0)
	{
		next = test;
		while(next && ft_strncmp(next->content, ra, 3) == 0)
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


void ft_opti_r_rr(t_listc **sol, int size_lst, char *ra, char *rra)
{
	t_listc	*test;
	t_listc	*cp;
	int i;

	test = *sol;
	while(test)
	{
		if(ft_opti_countr(test, size_lst, ra) > 0)
		{
			i = size_lst - ft_opti_countr(test, size_lst, ra);
			while (i > 0)
			{
				test->content = rra;
				i--;
				if(i > 0)
					test = test->next;
			}
			while (test->next && ft_strncmp(test->next->content, ra, 3) == 0)
			{
				cp = test->next->next;
				free(test->next);
				test->next = cp;
				if (ft_strncmp(test->next->content, ra, 3) != 0)
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
		// ft_opti_r_rr(sol, size_lst, "rra\n", "ra\n");
		// ft_opti_r_rr(sol, size_lst, "rra\n", "ra\n");
		ft_optisol_ss(sol);
		ft_optisol_rr(sol);
		ft_optisol_rrr(sol);
		printf("size of list: %d\n", size_lst);
	}
}
