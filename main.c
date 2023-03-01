/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/03/01 17:22:28 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

int	main(int argc, char **argv)
{
	int		value_max;
	char	**argvbrackets;
	t_list	*lst_a;
	t_list	*lst_b;
	t_listc	*sol;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argvbrackets = ft_split(argv[1], '"');
		argv = ft_split(argvbrackets [0], ' ');
		printf("%s\n", argv[0]);
	}
	if (ft_argvok(argv) == 0)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	printf("%s\n", argv[0]);
	lst_a = ft_lstdef(argc, argv);
	ft_lstprint(lst_a);
	lst_b = NULL;
	sol = NULL;
	value_max = 10;
	if (ft_lstsize(lst_a) < value_max)
		value_max = ft_lstsize(lst_a);
	ft_sort(&lst_a, &lst_b, value_max, &sol);
}
