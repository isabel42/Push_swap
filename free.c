/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/11 15:34:38 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

void	ft_free_pp_int(int **s)
{
	int	i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j] > 0)
		{
			s[i][j] = 0;
			j++;
		}
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_free_lst(t_list *lst)
{
	while(lst)
	{
		lst->content = 0;
		free(lst);
		lst = lst->next;
	}
}