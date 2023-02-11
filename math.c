/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/11 15:28:50 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

int	ft_recursive_factorial(int nb)
{	
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	return (nb * ft_recursive_factorial (nb - 1));
}

int	**ft_combi(int value_max, int size)
{
	int	**table;
	int	combinations;
	int	i;

	i = size + 1;
	combinations = ft_recursive_factorial(value_max)
		/ (ft_recursive_factorial(size)
			* ft_recursive_factorial(value_max - size));
	table = ft_calloc(sizeof(*table), combinations + 1);
	if (!table)
		return (NULL);
	while (combinations--)
	{
		table[combinations] = ft_calloc(sizeof(table), size + 1);
		if (!table)
		{
			ft_free_pp_int (table);
			return (NULL);
		}
	}
	while (i--)
		table[0][i - 1] = i;
	table = ft_combi_alloc(table, value_max, size);
	return (table);
}

int	**ft_combi_alloc(int **table, int value_max, int size)
{
	int	i;
	int	j;

	i = 1;
	while (table[i - 1][0] < value_max - size + 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (table[i - 1][j + 1] < value_max - (size - (j + 1 + 1)))
			{
				table[i][j] = table[i - 1][j];
				j++;
				continue ;
			}
			table[i][j] = table[i - 1][j] + 1;
			j++;
			break ;
		}
		ft_combi_alloc_bis(table, value_max, j, i);
		i++;
	}
	return (table);
}

int	**ft_combi_alloc_bis(int **table, int value_max, int j, int i)
{
	int	size;

	size = 0;
	while (table[0][size] > 0)
			size++;
	if (j == size - 1 && table[i - 1][j] < value_max - (size - (j + 1)))
	{
		table[i][j] = table[i - 1][j] + 1;
		j++;
	}
	j--;
	while (j++ < size)
		table[i][j] = table[i][j - 1] + 1;
	table[i][size] = 0;
	return (table);
}
