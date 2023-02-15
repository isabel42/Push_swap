/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/15 16:58:59 by itovar-n         ###   ########.fr       */
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
	r_list	*sol;
	// r_list	*second;

	if (ft_argvok(argv) == 0)
	{
		printf("%s", "Error\n");
		return (0);
	}
	lst_a = ft_lstdef(argc, argv);
	lst_b = NULL;
	sol = NULL;
	value_max = 50;
	if(ft_lstsize(lst_a) < value_max)
		value_max = ft_lstsize(lst_a);

	if(ft_lstsorted(lst_a) == 1)
	{
		ft_tocount_a(&lst_a, ft_lstbreak(lst_a), &sol);
		return(0);

	}
	ft_sort(&lst_a, &lst_b, value_max, &sol);
	// ft_tocount_a(&lst_a, ft_lsttrouble(lst_a), &sol);
	// ft_ns_tob(&lst_a, &lst_b, value_max, &sol);
	// if(ft_lstsorted(lst_a) == 1)
	// {
	// 	ft_btoa_s(&lst_a, &lst_b, &sol);
	// 	ft_tocount_a(&lst_a, ft_lstbreak(lst_a), &sol);
	// 	return(0);

	// }
	// ft_s_tob(&lst_a, &lst_b, value_max, &sol);
	// ft_btoa_s(&lst_a, &lst_b, &sol);


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
	printf("SOL:\n");
	// second = sol;
	// while (second)
	// {
	// 	printf("%s", second->content);
	// 	second = second->next;
	// }
	printf("size of sol %d: ", ft_lstsize_char(sol));
	free(sol);
	
}
