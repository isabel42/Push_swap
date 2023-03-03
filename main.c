/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/03/03 14:53:35 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

t_list	*ft_buildlst(int argc, char **argv)
{
	char	**single;
	char	**single1;
	t_list	*lst_a;
	
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], """", 2) == 0)
			exit(0);
		single = ft_split(argv[1], '"');
		single1 = ft_split(single [0], ' ');
		ft_argvok(single1, 0);
		lst_a = ft_lstdef(single1, 0);
		ft_free_pp_char(single);
		ft_free_pp_char(single1);
	}
	else
	{
		ft_argvok(argv, 1);
		lst_a = ft_lstdef(argv, 1);
	}
	return (lst_a);
}

int	main(int argc, char **argv)
{
	int		value_max;
	t_list	*lst_a;
	t_list	*lst_b;
	t_listc	*sol;

	lst_a = ft_buildlst(argc, argv);
	lst_b = NULL;
	sol = NULL;
	value_max = 10;
	if (ft_lstsize(lst_a) < value_max)
		value_max = ft_lstsize(lst_a);
	ft_sort(&lst_a, &lst_b, value_max, &sol);
}
