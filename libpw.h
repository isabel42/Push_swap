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
int		ft_argvok(char **argv);

int		ft_lstsorted(t_list *lst);
int		ft_lstsorted_rev(t_list *lst);
int		ft_lstsorted_s(t_list *lst);
int		ft_lstsorted_srev(t_list *lst);

int		ft_lst_i(t_list *lst_a, int i);
int		ft_lst_i_bis(t_list *lst_a, int i, int count, t_list *first);
int		ft_lstbreak(t_list *lst_a);
void	ft_tocount(t_list **lst_a, int count);
// void	ft_itotop(t_list **lst_a, int i);

t_list	*ft_lstdef(int argc, char **argv);
void	r(t_list **lstA);
void	rr(t_list **lstA);
void	p(t_list **lstA, t_list **lstB);
void	s(t_list **lstA);


void    ft_free_pp_int(int **s);
void	ft_free_lst(t_list *lst);

int		ft_fact(int nb);
int		**ft_combi(int value_max, int size);
int		**ft_combi_alloc(int **table, int value_max, int size);
int 	**ft_combi_alloc_bis(int **table, int value_max, int j, int i);

t_list	*ft_linetlstbuild(int *combi, t_list *lst, int value_max);
int 	*ft_longestlist(t_list *lst, int value_max);
int		*ft_longestlist_bis(int combi, int **table, t_list *lst, int value_max);
int		*ft_intcpy(int *table);

void	ft_toconflict(t_list **lst_a);
void 	ft_ns_tob(t_list **lst_a, t_list **lst_b, int value_max);
void 	ft_btoa_s(t_list **lst_a, t_list **lst_b);
void	ft_s_tob(t_list **lst_a, t_list **lst_b, int value_max);

#endif