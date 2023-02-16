/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/16 10:17:50 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

int	main(int argc, char **argv)
{
	int		value_max;
	t_list	*lst_a;
	t_list	*lst_b;
	t_listc	*sol;

	if (ft_argvok(argv) == 0)
	{
		printf("%s", "Error\n");
		return (0);
	}
	lst_a = ft_lstdef(argc, argv);
	lst_b = NULL;
	sol = NULL;
	value_max = 50;
	if (ft_lstsize(lst_a) < value_max)
		value_max = ft_lstsize(lst_a);
	ft_sort(&lst_a, &lst_b, value_max, &sol);
	ft_printlst_char(sol);
	free(sol);
}
