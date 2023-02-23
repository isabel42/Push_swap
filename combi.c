/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/22 23:04:44 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

long long ft_fact_2(int i, int j)
{
	long long result;

	result = 1;
	while (i > j)
	{
		result = result * i;
		i--;
	}
	return (result);
}

long long ft_combicount(int n, int k)
{
	int max;
	int min;
	long long result;

	max = n - k;
	min = k;
	if (min > max)
	{
		min = n - k;
		max = k;
	}
	result = ft_fact_2(n, max) / ft_fact_2(min, 0);
	return (result);
}

int	**ft_combi(int value_max, int size)
{
	int	**table;
	long long	combi;
	long long	i;

	i = size + 1;
	combi = ft_combicount(value_max, size);
	table = ft_calloc(sizeof(*table), combi + 1);
	if (!table)
		return (NULL);
	while (combi--)
	{
		table[combi] = ft_calloc(sizeof(table), size + 1);
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
	long long	i;
	long long	j;

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

int	**ft_combi_alloc_bis(int **table, int value_max, long long j, long long i)
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
