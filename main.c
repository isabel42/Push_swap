/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/06 18:58:39 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libpw.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*sol;
	size_t	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	sol = malloc((len_s1 + len_s2 + 1) * sizeof(*s1));
	if (!sol)
		return (NULL);
	while (i < len_s1)
	{
		sol[i] = s1[i];
		s1[i] = '\0';
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		sol[i] = s2[i - len_s1];
		i++;
	}
	free(s1);
	sol [i] = '\0';
	return (sol);
}

void ft_sort_three (t_list **lst_a, int argc)
{
	t_list *last;

	last = ft_lstlast(*lst_a);
		if( last->content < (*lst_a)->content)
		{
			r(lst_a);
			printf("ra\n");
		}
		else if ((*lst_a)->content > (*lst_a)->next->content)
		{
			s(lst_a);
			printf("sa\n");
		}
		else
		{
			rr(lst_a);
			printf("rra\n");
		}
		if (ft_lstsorted(*lst_a, argc - 1) == 0)
			ft_sort_three (lst_a, argc);
}

void ft_sort (t_list **lst_a, int argc)
{
	t_list *last;

	last = ft_lstlast(*lst_a);
	if ((*lst_a)->content > (*lst_a)->next->content)
	{
		s(lst_a);
		printf("sa\n");
	}
	else if (last->content < (*lst_a)->content)
	{
		r(lst_a);
		printf("ra\n");
	}
	else
	{
		rr(lst_a);
		printf("rra\n");
	}
	if (ft_lstsorted(*lst_a, argc - 1) == 0)
	{
		ft_sort (lst_a, argc);
	}
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*first;

	printf("**********\n");
	if (ft_argvok(argv) == 0)
	{
		printf("%s", "Error\n");
		return (0);
	}
	lst_a = ft_lstdef(argc, argv);
	if (ft_lstsorted(lst_a, argc - 1) == 1)
		return (0);
	//r(&lst_a);
	ft_sort (&lst_a, argc);
	first = lst_a;
	while (first)
	{
		printf("%d\n", first->content);
		first = first->next;
	}
	printf("----\n");
	/*first = lst_b;
	while (first)
	{
		printf("%d\n", first->content);
		first = first->next;
	}*/
}
