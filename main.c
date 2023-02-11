/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/11 23:27:41 by itovar-n         ###   ########.fr       */
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

int	ft_lstbreak(t_list *lst_a)
{
	int		count;
	int		prev_content;
	t_list	*first;

	count = 0;
	first = lst_a;
	prev_content = ft_lstlast(lst_a)->content;
	while (first->next)
	{
		if (prev_content > first->content)
			break ;
		count++;
		first = first->next;
	}
	return (count);
}

void	ft_mintotop(t_list **lst_a)
{
	t_list	*last;
	int		count;
	int		size;

	count = ft_lstbreak(*lst_a);
	size = ft_lstsize(*lst_a);
	last = ft_lstlast(*lst_a);
	if (2 * count < size)
	{
		while (last->content < (*lst_a)->content)
		{
			r(lst_a);
			printf("ra\n");
			last = ft_lstlast(*lst_a);
		}
	}
	else
	{
		while (last->content < (*lst_a)->content)
		{
			rr(lst_a);
			printf("rra\n");
			last = ft_lstlast(*lst_a);
		}
	}
}

void	ft_sort_three(t_list **lst_a)//, int argc)
{
	s(lst_a);
	printf("sa\n");
	ft_mintotop(lst_a);
}

void	ft_sort(t_list **lst_a, int argc, int i)
{
	t_list	*last;

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
	if (ft_lstsorted(*lst_a) == 0 && i < 20)
	{
		i++;
		ft_sort (lst_a, argc, i);
	}
	ft_mintotop(lst_a);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_list	*first;
	t_list	*last;
	int		*best;
	int		**table;
	int i;
	int j;

	if (ft_argvok(argv) == 0)
	{
		printf("%s", "Error\n");
		return (0);
	}
	lst_a = ft_lstdef(argc, argv);
	lst_b = NULL;
	table = ft_combi(10, 1);
	best = ft_longestlist(lst_a, 10);
	j = 0;
	i = 1;
	while (i <= 10)
	{
		if(i == best [j])
		{
			r(&lst_a);
			j++;
		}
		else
		{
			while((lst_b) && lst_b content)
			p(&lst_a, &lst_b);
		}
			
		i++;
	}
	if(ft_lstsorted(lst_a) == 1)
	{
		while (lst_b)
		{
			last = ft_lstlast(lst_a);
			if ((lst_a->content > lst_b->content && lst_b->content > last->content) || ((lst_a->content  > lst_b->content || lst_b->content > last->content) && ft_lstsorted_s(lst_a) == 1) )
				p(&lst_b, &lst_a);
			 else
				 rr(&lst_a);
		}
	}
	i = 0;
	printf("\nTable: ");
	while( i < 1)
	{	
		j = 0;
		while(j < 1)
		{
			printf("%d, ", table[i][j]);
			j++;
		}
		i++;
	}
	printf("\nBest: ");
	i = 0;
	while( best[i] > 0)
	{
		printf("%d, ", best[i]);
		i++;
	}
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
