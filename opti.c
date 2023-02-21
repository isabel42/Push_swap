/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/21 12:49:14 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

void	ft_optisol_rp(t_listc **sol)
{
	t_listc	*cp;
	t_listc	*test;

	test = *sol;
	while (test && test->next && test->next->next)
	{
		if (ft_optisol_rp_bis(test->next->content,
				test->next->next->content) == 1)
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

int	ft_optisol_rp_bis(char *test_next, char *test_next_next)
{
	if ((ft_strncmp(test_next, "ra\n", 3) == 0
			&& ft_strncmp(test_next_next, "rra\n", 4) == 0)
		|| (ft_strncmp(test_next, "rb\n", 3) == 0
			&& ft_strncmp(test_next_next, "rrb\n", 4) == 0)
		|| (ft_strncmp(test_next, "rra\n", 4) == 0
			&& ft_strncmp(test_next_next, "ra\n", 3) == 0)
		|| (ft_strncmp(test_next, "rrb\n", 4) == 0
			&& ft_strncmp(test_next_next, "rb\n", 3) == 0)
		|| (ft_strncmp(test_next, "pa\n", 3) == 0
			&& ft_strncmp(test_next_next, "pb\n", 3) == 0)
		|| (ft_strncmp(test_next, "pb\n", 3) == 0
			&& ft_strncmp(test_next_next, "pa\n", 3) == 0))
		return (1);
	return (0);
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
