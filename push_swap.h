/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:41:38 by tnicoue           #+#    #+#             */
/*   Updated: 2022/03/03 10:44:44 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stock
{
	int				bigger;
	int				pos_bigger;
	int				shorter;
	int				shorter2;
	int				pos_shorter;
	int				pos_shorter2;
	int				size_a;
	int				size_b;
	int				lastb;
	int				pos;
	int				pos2;
	int				bc;
	int				var_tabcheck;
	int				done;
	int				value;
	int				oldbig;
	int				biggerb;
	int				lowerb;
	int				checklast;
	int				chunk_size;
}	t_stock;

t_stack	*ft_lstnew(int content);
void	ft_checkb(t_stack **stack_b, t_stock *stock);
void	ft_m(int a, void (*pf)(t_stack **s), t_stack **st);
void	ft_prep(t_stack **stack_a, t_stack **stack_b, t_stock *stock);
void	ft_biggerchunk_a(t_stack **stack_a, t_stock *stock);
void	get_size_a(t_stack **stack_a, t_stock *stock);
long	ft_atoi(const char *str);
void	ft_lstadd_front(t_stack **alst, t_stack *new);
void	getbigger(t_stack **stack_a, t_stock *stock);
void	ft_checkaccept(t_stack **stack_a, t_stock *stock);
void	nmkcoup(t_stock *stock);
int		ft_checktab(int valeur, int *tab, int size);
void	ft_accept_a(t_stack**stack_a, t_stock *stock);
int		checklowercoup(t_stock*stock);
void	ft_last(t_stack **stack_b, t_stock *stock);
int		ft_lastb(t_stack **stack_b);
void	mvlowercoup(int indic, t_stock *stock, t_stack **stack_a);
void	ft_mvfirst(t_stock *stock, int pos, t_stack **a, t_stack**b);
void	ft_tri100(t_stack **stack_a, t_stack **stack_b, t_stock *stock);
void	mvbigger(t_stack **stack_a, t_stack **stack_b, t_stock *stock);
void	mvbigger2(t_stack **stack_b, t_stock *stock);
void	ft_tri5(t_stack **stack_a, t_stack **stack_b, t_stock *stock);
void	ft_tribig(t_stack **stack_a, t_stack **stack_b, t_stock *stock);

void	ft_pos_accept(t_stack **stack_a, t_stack **b, t_stock *stock);
void	ft_pos_accept2(t_stack **stack_a, t_stack **stack_b, t_stock *stock);
void	ft_pos_accept3(t_stack **a, t_stack **b, t_stock *stock, int pos);
void	mvlower4(t_stack **stack_a, t_stack **stack_b, t_stock *stock);
void	ft_crea_tab_pos(t_stack **stack_a, t_stock *stock);
void	direction(t_stack **stack_a, t_stack **stack_b, t_stock *stock);
void	getlower4_5(t_stack **stack_a, t_stock *stock);
int		get_size(t_stack **stack, t_stock *stock);
void	ft_lstadd_back(t_stack **alst, t_stack *n);
void	ft_rotate_max(t_stack **a, t_stack **b, t_stock *stock, int max);
void	ft_mvmax(t_stack **a, t_stack **b, t_stock *stock, int max);
int		ft_bigger_b(t_stack **stack_b);
int		ft_lower_b(t_stack **stack_b);
void	ft_tri4(t_stack **stack_a, t_stack **stack_b, t_stock *stock);
void	ft_init_struct(t_stack **stack_a, t_stock *stack);
void	ft_print_lst(t_stack *stack);
void	free_split(char **cpy_argv);
void	ft_tri3(t_stack **stack_a);
void	ft_tri2(t_stack **stack_a);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_onsenfou(char *str);
int		ft_verifclean(t_stack *stack_a);
int		ft_verifint(t_stack *stack_a);
int		ft_verifnorecurse(t_stack *stack_a);
int		ft_strcmp(char *s1, char *s2);
int		ft_mklist(t_stack **stack_a, int argc, char **argv);
int		ft_chklist(int argc, char **argv);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		main(int argc, char **argv);
int		ft_check_order(t_stack *stack_a);
void	ft_lstclear(t_stack **lst);
void	mkchunk(t_stock *stock);
void	ft_chunk(t_stock *stock, t_stack **a, t_stack**b);
int		ft_checkpos(int check, t_stack **stack_a);
int		checkcp(int i, t_stock *stock);
void	ft_mvoldbig(t_stack**stack_a, t_stock *stock);

void	ft_sa(t_stack **stack);
void	ft_sb(t_stack **stack);
void	ft_ra(t_stack **stack);
void	ft_rb(t_stack **stack);
void	ft_rra(t_stack **stack);
void	ft_rrb(t_stack **stack);
void	ft_pa(t_stack **stack_b, t_stack **stack_a, t_stock *stock);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, t_stock *stock);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);

#endif
/*
SA / SB / SS

on save le premier element, on recupere la valeur 
du deuxieme element qu on affecte au premier lsta->content = lsta->next
lsta->next = save;

PA / PB 

on save les elements de a 1 par 1 en
 bouclant jusqu'a lsta->next == NULLlstb->content 
*/
