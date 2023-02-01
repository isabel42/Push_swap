/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:15 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/01 17:42:50 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"

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

t_list	*ft_lstdef(int argc, char **argv)
{
	t_list	*new;
	t_list	*second;
	int		i;

	new = ft_lstnew(ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
	{
		second = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&new, second);
		i++;
	}
	return (new);
}

void	r(t_list **lstA)
{
	t_list	*first;
	t_list	*last;

	if (*lstA)
	{
		first = *lstA;
		last = ft_lstlast(*lstA);
		last->next = first;
		*lstA = first->next;
		first->next = NULL;
	}
}

void	rr(t_list **lstA)
{
	t_list	*first;
	t_list	*last;
	t_list	*before_last;

	if (*lstA)
	{
		first = *lstA;
		before_last = *lstA;
		while (before_last->next->next)
			before_last = before_last->next;
		last = ft_lstlast(*lstA);
		*lstA = last;
		last->next = first;
		before_last->next = NULL;
	}
}

void	p(t_list **lstA, t_list **lstB)
{
	t_list	*first_a;
	t_list	*first_b;

	if (*lstA != NULL)
	{
	first_a = *lstA;
	first_b = *lstB;
	*lstB = first_a;
	*lstA = first_a->next;
	first_a->next = first_b;
	}
}

void	s(t_list **lstA)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (*lstA)
	{
		first = *lstA;
		second = first->next;
		third = first->next->next;
		*lstA = second;
		second->next = first;
		second->next->next = third;
	}	
}

int	ft_argvdup(char **argv)
{
	int	i;
	int j;

	i = 0;
	while(argv[i])
	{
		if (argv[i][0] == '+')
			argv[i] = argv[i] + 1;
		j = 0;
		while ((argv[j]))
		{
			if (argv[j][0] == '+')
			argv[j] = argv[j] + 1;
			if (ft_strncmp(argv[i], argv[j], 11) == 0)
				return(0);
			j++;
		}
	i++;
	}
	return (1);

}

int	ft_argvisdigit(char *argv)
{
	int	i;
	int	len;
	int sign;

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
		return(0);
	return (1);
}

int	ft_argvisint(char *argv)
{
	int		j;
	int		k;
	char	*int_max;
	int		sign;
	int		len;

	j = 0;
	k = 0;
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
	if (len - sign > 10  || (len - sign == 10 && ft_strncmp(argv, int_max, 10 + sign) > 0))
		return (0);
	return (1);
}

int	ft_lstsorted(t_list *lst, int argc)
{
	int	i;

	i = 0;
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
		i++;
	}
	if (i + 1 < argc)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_list	*first;
	t_list	*second;
	int		i;

	lst_a = ft_lstdef(argc, argv);
	if (ft_lstsorted(lst_a, argc - 1) == 1)
		return(0);
	i = 1;
	while (i < argc)
	{
		printf("is int: %d\n", ft_argvisint (argv[i]));
		i++;
	}
	printf("char dup: %d\n", ft_argvdup(argv));
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
