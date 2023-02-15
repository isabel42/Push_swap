/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/15 12:40:26 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

void	ft_sort_three(t_list **lst_a)//, int argc)
{
	s(lst_a);
	printf("sa\n");
	ft_tocount(lst_a, ft_lstbreak(*lst_a));
}

int	main(int argc, char **argv)
{
	int		value_max;
	t_list	*lst_a;
	t_list	*lst_b;
	t_list	*first;

	value_max = 6;
	if (ft_argvok(argv) == 0)
	{
		printf("%s", "Error\n");
		return (0);
	}
	lst_a = ft_lstdef(argc, argv);
	lst_b = NULL;
	printf("To i: %d \n", ft_lst_i(lst_a, 60));
	printf("Value max: %d \n", value_max);
	// if(ft_lstsorted(lst_a) == 1)
	// {
	// 	ft_breaktotop(&lst_a);
	// 	return(0);
	// }
	// ft_itotop(&lst_a, 60);
	// lst_b = ft_lstnew(30);
	// p(&lst_b, &lst_a);
	// ft_breaktotop(&lst_a);
	
	ft_toconflict(&lst_a);
	ft_ns_tob(&lst_a, &lst_b, value_max);
	if(ft_lstsorted(lst_a) == 1)
		ft_btoa_s(&lst_a, &lst_b);
	else
		ft_s_tob(&lst_a, &lst_b, value_max);


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
