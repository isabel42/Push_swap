/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/20 16:13:38 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

void	ft_optisol_r(t_listc **sol)
{
	t_listc	*cp;
	t_listc	*test;

	test = *sol;
	while (test && test->next && test->next->next)
	{
		if ((ft_strncmp(test->next->content, "ra\n", 3) == 0
				&& ft_strncmp(test->next->next->content, "rra\n", 4) == 0)
			|| (ft_strncmp(test->next->content, "rb\n", 3) == 0
				&& ft_strncmp(test->next->next->content, "rrb\n", 4) == 0)
			|| (ft_strncmp(test->next->content, "rra\n", 3) == 0
				&& ft_strncmp(test->next->next->content, "ra\n", 4) == 0)
			|| (ft_strncmp(test->next->content, "rrb\n", 3) == 0
				&& ft_strncmp(test->next->next->content, "rb\n", 4) == 0))
		{
			cp = test->next->next->next;
			free(test->next);
			free(test->next->next);
			test->next = cp;
			test = *sol;
			continue ;
		}
		test = test->next;
	}
}

void	ft_optisol_ss(t_listc **sol)
{
	t_listc	*cp;
	t_listc	*test;

	test = *sol;
	while (test->next)
	{
		if ((ft_strncmp(test->content, "sa\n", 3) == 0
				&& ft_strncmp(test->next->content, "sb\n", 3) == 0)
			|| (ft_strncmp(test->content, "sb\n", 3) == 0
				&& ft_strncmp(test->next->content, "sa\n", 3) == 0))
		{
			test->content = "ss\n";
			cp = test->next->next;
			free(test->next);
			test->next = cp;
			test = *sol;
			continue ;
		}
		test = test->next;
	}
}

void	ft_optisol_rr(t_listc **sol)
{
	t_listc	*cp;
	t_listc	*test;

	test = *sol;
	while (test->next)
	{
		if ((ft_strncmp(test->content, "ra\n", 3) == 0
				&& ft_strncmp(test->next->content, "rb\n", 3) == 0)
			|| (ft_strncmp(test->content, "rb\n", 3) == 0
				&& ft_strncmp(test->next->content, "ra\n", 3) == 0))
		{
			test->content = "rr\n";
			cp = test->next->next;
			free(test->next);
			test->next = cp;
			test = *sol;
			continue ;
		}
		test = test->next;
	}
}

void	ft_optisol_rrr(t_listc **sol)
{
	t_listc	*cp;
	t_listc	*test;

	test = *sol;
	while (test->next)
	{
		if ((ft_strncmp(test->content, "rra\n", 3) == 0
				&& ft_strncmp(test->next->content, "rrb\n", 3) == 0)
			|| (ft_strncmp(test->content, "rrb\n", 3) == 0
				&& ft_strncmp(test->next->content, "rra\n", 3) == 0))
		{
			test->content = "rrr\n";
			cp = test->next->next;
			free(test->next);
			test->next = cp;
			test = *sol;
			continue ;
		}
		test = test->next;
	}
}

void	ft_optisol(t_listc **sol)
{
	if (*sol)
	{
		ft_optisol_r(sol);
		ft_optisol_ss(sol);
		ft_optisol_rr(sol);
		ft_optisol_rrr(sol);
	}
}
