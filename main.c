/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/13 17:42:33 by itovar-n         ###   ########.fr       */
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

void	ft_sort_three(t_list **lst_a)//, int argc)
{
	s(lst_a);
	printf("sa\n");
	ft_breaktotop(lst_a);
}

int	main(int argc, char **argv)
{
	int		value_max;
	t_list	*lst_a;
	t_list	*lst_b;
	t_list	*first;
	// t_list	*last;

	value_max = 3;
	if (ft_argvok(argv) == 0)
	{
		printf("%s", "Error\n");
		return (0);
	}
	lst_a = ft_lstdef(argc, argv);
	lst_b = NULL;
	printf("To i: %d \n", ft_lst_i(lst_a, 2));
	ft_ns_tob(&lst_a, &lst_b, value_max);
	// if(ft_lstsorted(lst_a) == 1)
	// {
	// 	while (lst_b)
	// 	{
	// 		ft_itotop(&lst_a, lst_b->content);
	// 		p(&lst_b, &lst_a);
	// 	}
	// }
	printf("\n----\nA:");
	first = lst_a;
	while (first)
	{
		printf("%d, ", first->content);
		first = first->next;
	}
	printf("\nB:");
	first = lst_b;
	while (first)
	{
		printf("%d, ", first->content);
		first = first->next;
	}
	printf("\n");

}
