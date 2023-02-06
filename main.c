/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/02 11:55:10 by itovar-n         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*first;

	printf("**********\n");
	if (ft_argvok(argv) == 0)
	{
		printf("%s","Error\n");
		return(0);
	}
	lst_a = ft_lstdef(argc, argv);
	if (ft_lstsorted(lst_a, argc - 1) == 1)
		return (0);
	s(&lst_a);
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
