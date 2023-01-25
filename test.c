#include <stdio.h>
# include "./libft/libft.h"

int main(int argc, char **argv)
{
	//char *c = argv[1];
	int b = argc;
	int i;

	t_list *new;
	t_list **lst;

	int *a;
	i = 1;
	a = malloc(sizeof(int) * (b - 1));
	new = ft_lstnew(ft_atoi(argv[1]));
	//new = ft_lstnew(ft_atoi(argv[2]));
	*lst = NULL;
printf("%d\n", new->content);
	ft_lstadd_front(lst, new);
	while( i < b )
	{
		a[i] = ft_atoi(argv [i]);
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");
	
}
