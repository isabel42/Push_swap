/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstA.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/15 16:22:08 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

t_list	*ft_lstdef(int argc, char **argv)
{
	t_list	*new;
	t_list	*second;
	int		i;

	new = ft_lstnew(ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
	{
		second = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&new, second);
		i++;
	}
	return (new);
}

void	ra(t_list **lstA, r_list **sol)
{
	t_list	*first;
	t_list	*last;


	if (*lstA && ft_lstsize(*lstA) > 1)
	{
		first = *lstA;
		last = ft_lstlast(*lstA);
		last->next = first;
		*lstA = first->next;
		first->next = NULL;
	}

	if(*sol == NULL)
		*sol = ft_lstnew_char("ra\n");

	else
		ft_lstadd_back_char(sol, ft_lstnew_char("ra\n"));
}

void	rra(t_list **lstA, r_list **sol)
{
	t_list	*first;
	t_list	*last;
	t_list	*before_last;

	if (*lstA)
	{
		first = *lstA;
		before_last = *lstA;
		while (before_last->next->next)
			before_last = before_last->next;
		last = ft_lstlast(*lstA);
		*lstA = last;
		last->next = first;
		before_last->next = NULL;
	}

	if(*sol == NULL)
		*sol = ft_lstnew_char("rra\n");
	else
		ft_lstadd_back_char(sol, ft_lstnew_char("rra\n"));
}

void	pa(t_list **lstA, t_list **lstB, r_list **sol)
{
	t_list	*first_a;
	t_list	*first_b;

	if (*lstA != NULL)
	{
	first_a = *lstA;
	first_b = *lstB;
	*lstB = first_a;
	*lstA = first_a->next;
	first_a->next = first_b;
	}
	if(sol == NULL)
		*sol = ft_lstnew_char("pa\n");
	else
		ft_lstadd_back_char(sol, ft_lstnew_char("pa\n"));
}

void	sa(t_list **lstA, r_list **sol)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (*lstA && (*lstA)->next)
	{
		first = *lstA;
		second = first->next;
		third = first->next->next;
		*lstA = second;
		second->next = first;
		second->next->next = third;
	}
	if(sol == NULL)
		*sol = ft_lstnew_char("sa\n");
	else
		ft_lstadd_back_char(sol, ft_lstnew_char("sa\n"));
}
