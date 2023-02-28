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

typedef struct c_list
{
	char			*content;
	struct c_list	*next;
}t_listc;

int			ft_argvdup(char **argv);
int			ft_argvisdigit(char *argv);
int			ft_argvisint(char *argv);
int			ft_argvok(char **argv);

int			ft_lstsorted(t_list *lst);
int			ft_lstsorted_rev(t_list *lst);
int			ft_lstsorted_s(t_list *lst);
int			ft_lstsorted_srev(t_list *lst);

int			ft_lst_i(t_list *lst_a, int i);
int			ft_lst_i_bis(t_list *lst_a, int i, int count, t_list *first);
int			ft_lstbreak(t_list *lst_a);
int			ft_lsttrouble(t_list *lst_a);

void		ft_tocount_a(t_list **lst_a, int count, t_listc **sol);
void		ft_tocount_b(t_list **lst_a, int count, t_listc **sol);
void		ft_totroube(t_list **lst_a, t_listc **sol);

void		ft_lstadd_back_char(t_listc **lst, t_listc *new);
t_listc		*ft_llastc(t_listc *lst);
int			ft_lstsize_char(t_listc *lst);
void		ft_printlst_char(t_listc *sol);

t_list		*ft_lstdef(int argc, char **argv);
void		ra(t_list **lstA, t_listc **sol);
void		rra(t_list **lstA, t_listc **sol);
void		pa(t_list **lstA, t_list **lstB, t_listc **sol);
void		sa(t_list **lstA, t_listc **sol);

t_listc		*ft_lstnew_char(char *content);
void		rb(t_list **lstA, t_listc **sol);
void		rrb(t_list **lstA, t_listc **sol);
void		pb(t_list **lstA, t_list **lstB, t_listc **sol);
void		sb(t_list **lstA, t_listc **sol);

void		ft_free_pp_int(int **s);
void		ft_free_lst(t_list *lst);
void		ft_free_lst_char(t_listc *lst);
void		ft_ps_exit(t_list **lst_a, t_listc **sol);

long long	ft_fact_2(int i, int j);
long long	ft_combicount(int n, int k);
int			**ft_combi(int value_max, int size);
int			**ft_combi_alloc(int **table, int value_max, int size);
int			**ft_combi_alloc_bis(int **table,
				int value_max, long long j, long long i);

t_list		*ft_linetlstbuild(int *combi, t_list *lst, int value_max);
int			*ft_longestlist(t_list *lst, int value_max);
int			*ft_longestlist_bis(int combi, int **table,
				t_list *lst, int value_max);
int			*ft_intcpy(int *table);

void		ft_sort_three(t_list **lst_a, t_listc **sol);
void		ft_ns_tob(t_list **lst_a, t_list **lst_b,
				int value_max, t_listc **sol);
void		ft_btoa_s(t_list **lst_a, t_list **lst_b,
				t_listc **sol, int value_max);
void		ft_s_tob(t_list **lst_a, t_list **lst_b,
				int value_max, t_listc **sol);
void		ft_sort(t_list **lst_a, t_list **lst_b,
				int value_max, t_listc **sol);
void		ft_chekthree_sorted(t_list **lst_a, t_list **lst_b,
				int value_max, t_listc **sol);

void		ft_optisol_rp(t_listc **sol);
int			ft_optisol_rp_bis(char *test_next, char *test_next_next);
void		ft_optisol_ss(t_listc **sol);
void		ft_optisol_rr(t_listc **sol);
void		ft_optisol_rrr(t_listc **sol);

void		ft_optisol(t_listc **sol);

#endif