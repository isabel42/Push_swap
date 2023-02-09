/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/09 10:21:27 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

void	ft_free(char **s, int j)
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

int	**ft_combi_malloc(int value_max, int size)
{
	int	**table;
	int	combinations;
	int	i;

	i = 0;
	combinations = ft_recursive_factorial(value_max)
		/ (ft_recursive_factorial(size)
			* ft_recursive_factorial(value_max - size));
	*table = malloc(sizeof(int) * combinations);
	if (!table)
		return (NULL);
	while (i < combinations)
	{
		table[i] = malloc(sizeof(int) * size);
		if (!table)
		{
			ft_free (table, i);
			return (NULL);
		}
		i++;
	}
	while (size--)
		table[0][size - 1] = size;
	return (table);
}

int	**ft_combi(int value_max, int size)
{
	int	i;
	int	j;
	int	**table;

	j = 0;
	i = 1;
	table = ft_combi_malloc(value_max, size);
	(while (table[i-1][0] != value_max - size + 1)
	{
		if (j < size -1 && table)
	}
	)


}