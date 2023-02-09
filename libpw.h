/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpw.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:24:46 by itovar-n          #+#    #+#             */
/*   Updated: 2023/02/02 09:33:25 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPW_H
# define LIBPW_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int		ft_argvdup(char **argv);
int		ft_argvisdigit(char *argv);
int		ft_argvisint(char *argv);
int		ft_lstsorted(t_list *lst, int argc);
int		ft_argvok(char **argv);

char	*ft_strjoin_free(char *s1, char *s2);

t_list	*ft_lstdef(int argc, char **argv);
void	r(t_list **lstA);
void	rr(t_list **lstA);
void	p(t_list **lstA, t_list **lstB);
void	s(t_list **lstA);

void    ft_free_int(int **s, int j);
int		ft_recursive_factorial(int nb);
int		**ft_combi(int value_max, int size);
int		**ft_combi_alloc(int **table, int value_max, int size);
int		**ft_combi_alloc_1(int **table, int value_max, int size);
int		**ft_combi_alloc_2(int **table, int value_max, int size);

#endif