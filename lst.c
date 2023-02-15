/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstA.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/15 14:07:56 by itovar-n         ###   ########.fr       */
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

void	r(t_list **lstA)
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
}

void	rr(t_list **lstA)
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
}

void	p(t_list **lstA, t_list **lstB)
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
}

void	s(t_list **lstA)
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
}
