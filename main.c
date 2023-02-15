/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/15 14:06:00 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

int	main(int argc, char **argv)
{
	int		value_max;
	t_list	*lst_a;
	t_list	*lst_b;
	t_list	*first;
	// r_list	*sol;

	if (ft_argvok(argv) == 0)
	{
		printf("%s", "Error\n");
		return (0);
	}
	lst_a = ft_lstdef(argc, argv);
	lst_b = NULL;
	value_max = 10;

	ft_tocount(&lst_a, ft_lsttrouble(lst_a));
	ft_ns_tob(&lst_a, &lst_b, value_max);
	if(ft_lstsorted(lst_a) == 1)
		ft_btoa_s(&lst_a, &lst_b);
	else
		ft_s_tob(&lst_a, &lst_b, value_max);
	ft_btoa_s(&lst_a, &lst_b);

	printf("\n----\nA:");
	first = lst_a;
	while (first)
	{
		printf("%d, ", first->content);
		first = first->next;
	}
	printf("\nB:");
	first = lst_b;
	while (first)
	{
		printf("%d, ", first->content);
		first = first->next;
	}
	printf("\n");
}
