/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstB.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/21 12:32:00 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

t_listc	*ft_lstnew_char(char *content)
{
	t_listc	*lstnew;

	lstnew = ft_calloc(sizeof (*lstnew), 1);
	if (lstnew == NULL)
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}

void	rb(t_list **lstA, t_listc **sol)
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
	if (sol == NULL)
		*sol = ft_lstnew_char("rb\n");
	else
		ft_lstadd_back_char(sol, ft_lstnew_char("rb\n"));
}

void	rrb(t_list **lstA, t_listc **sol)
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
	if (sol == NULL)
		*sol = ft_lstnew_char("rrb\n");
	else
		ft_lstadd_back_char(sol, ft_lstnew_char("rrb\n"));
}

void	pb(t_list **lstA, t_list **lstB, t_listc **sol)
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
	if (sol == NULL)
		*sol = ft_lstnew_char("pa\n");
	else
		ft_lstadd_back_char(sol, ft_lstnew_char("pa\n"));
}

void	sb(t_list **lstA, t_listc **sol)
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
	if (sol == NULL)
		*sol = ft_lstnew_char("sb\n");
	else
		ft_lstadd_back_char(sol, ft_lstnew_char("sb\n"));
}
