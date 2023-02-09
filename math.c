/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/09 13:36:28 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

void	ft_free_int(int **s, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(s[i]);
	}
	free(s);
}

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
		table[combinations] = ft_calloc(sizeof(table), size);
		if (!table)
		{
			ft_free_int (table, combinations);
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

	j = 0;
	i = 1;
	while (table[i - 1][0] < value_max - size + 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (table[i - 1][j + 1] < value_max - (size - (j + 1 + 1)))
				table[i][j] = table[i - 1][j];
			else
			{
				table[i][j] = table[i - 1][j] + 1;
				j++;
				break ;
			}
			j++;
		}
		if (j == size - 1 && table[i - 1][j] < value_max - (size - (j + 1)))
		{
			table[i][j] = table[i - 1][j] + 1;
			j++;
		}
		j--;
		while (j++ < size)
			table[i][j] = table[i][j - 1] + 1;
		i++;
	}
	return (table);
}
