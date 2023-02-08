/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/08 13:07:17 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

int	ft_argvdup(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '+')
			argv[i] = argv[i] + 1;
		j = i + 1;
		while ((argv[j]))
		{
			if (argv[j][0] == '+')
				argv[j] = argv[j] + 1;
			if (ft_strncmp(argv[i], argv[j], 11) == 0)
				return (1);
			j++;
		}
	i++;
	}
	return (0);
}

int	ft_argvisdigit(char *argv)
{
	int	i;
	int	len;
	int	sign;

	i = 0;
	sign = 0;
	len = (int) ft_strlen(argv);
	if (argv[0] == '-' || argv[0] == '+')
		sign++;
	while (i + sign < len)
	{
		if (ft_isdigit(argv[i + sign]) == 0)
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	ft_argvisint(char *argv)
{
	char	*int_max;
	int		sign;
	int		len;

	sign = 0;
	len = (int) ft_strlen(argv);
	if (argv[0] == '-' || argv[0] == '+')
		sign++;
	if (argv[0] == '-')
		int_max = "-2147483648";
	else if (argv[0] == '+')
		int_max = "+2147483647";
	else
		int_max = "2147483647";
	if (len - sign > 10
		|| (len - sign == 10 && ft_strncmp(argv, int_max, 10 + sign) > 0))
		return (0);
	return (1);
}

int	ft_argvok(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_argvisdigit(argv[i]) == 0 || ft_argvisint(argv[i]) == 0)
			return (0);
		i++;
	}
	if (ft_argvdup(argv) == 1)
		return (0);
	return (1);
}

int	ft_lstsorted(t_list *lst, int argc)
{
	int	i;
	int b;
	int last;
	int first;

	i = 0;
	b = 0;
	first = lst->content;
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			b++;
		lst = lst->next;
		i++;
	}
	last = ft_lstlast(lst)->content;
	if (first < last)
			b++;
	if (i + 1 < argc || b > 1)
		return (0);
	return (b);
}
