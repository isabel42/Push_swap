/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/03/02 13:40:53 by itovar-n         ###   ########.fr       */
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
	int		i;

	i = 1;
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], """", 2) == 0)
			return (0);
		argv = ft_split(argv[1], '"');
		argv = ft_split(argv [0], ' ');
		i = 0;
	}
	ft_argvok(argv, i);
	lst_a = ft_lstdef(argv, i);
	lst_b = NULL;
	sol = NULL;
	value_max = 10;
	if (ft_lstsize(lst_a) < value_max)
		value_max = ft_lstsize(lst_a);
	ft_sort(&lst_a, &lst_b, value_max, &sol);
}
