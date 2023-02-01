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

t_list	**ft_lstdef(int argc, char **argv)
{
	t_list	*new;
	t_list	*second;
	t_list	**lst;
	int		i;

	new = ft_lstnew(ft_atoi(argv[1]));
	lst = &new;
	i = 2;
	while (i < argc)
	{
		second = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(lst, second);
		i++;
	}
	return (lst);
}

int	ft_lstsorted(t_list **lst, int argc)
{
	int		i;
	t_list	*first;

	i = 0;
	first = *lst;
	while (first->next)
	{
		if (first->content > first->next->content)
			return (0);
		first = first->next;
		i++;
	}
	if (i + 1 < argc)
		return (0);
	return (1);
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

char	*ft_intmax(char *argv)
{
	if (argv[0] == '-')
		return ("2147483648");
	return ("2147483647");
}

int	ft_argvisdigit(char *argv)
{
	int	i;

	i = 0;
	while (i < ft_strlen(argv))
	{
		if (ft_isdigit(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_argvisint(char *argv)
{
	int		j;
	int		k;
	char	*int_max;
	int		minus;

	j = 0;
	k = 0;
	minus = 0;
	if (argv[0] == '-')
		minus++;
	int_max = ft_intmax(argv);
	while (j + minus < ft_strlen(argv))
	{
		if (argv[j + minus] < int_max[j])
			k++;
		if (ft_strlen(argv) - minus > ft_strlen(int_max)
			|| (argv[j + minus] > int_max[j] && k == 0
			&& (ft_strlen(argv) - minus) == ft_strlen(int_max)))
			return (0);
		j++;
	}
	return (1);
}

int	ft_checkargv(int argc, char **argv)
{
	int		j;
	char	*int_max;
	int		minus;

	while (argc--)
	{
		j = 0;
		minus = 0;
		if (argv[argc + 1][j] == '-')
			minus++;
		int_max = ft_intmax(argv[argc + 1]);
		while (j + minus < ft_strlen(argv[argc + 1]))
		{
			if (ft_isdigit(argv[argc + 1][j + minus]) == 0)
				return (0);
			if (ft_strlen(argv[argc + 1]) - minus > ft_strlen(int_max)
				|| (argv[argc + 1][j + minus] > int_max[j]
				&& (ft_strlen(argv[argc + 1]) - minus) == ft_strlen(int_max)))
				return (0);
			j++;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	**lst_a;
	t_list	**lst_b;
	t_list	*first;
	t_list	*second;
	char	*test;

	printf("++%d++\n", ft_argvisint(argv[3]));
	lst_a = ft_lstdef(argc, argv);
	*lst_b = NULL;
	if (ft_lstsorted(lst_a, argc - 1) == 1)
		return (0);
	p(lst_a, lst_b);
	p(lst_a, lst_b);
	first = *lst_a;
	while (first)
	{
		printf("%d\n", first->content);
		first = first->next;
	}
	printf("----\n");
	second = *lst_b;
	while (second)
	{
		printf("%d\n", second->content);
		second = second->next;
	}
}
