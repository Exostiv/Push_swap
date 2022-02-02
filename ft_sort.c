


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:25:18 by tnicoue           #+#    #+#             */
/*   Updated: 2022/01/25 18:26:20 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void get_bigger_b(t_stack *)
{
    int i;

    i = 0
    while (stack_b)
    {
        if(bigger < stack_b->content)
            bigger = stack_b->content;
        stack_b = stack_b->next;
    }
    while (t_stack * t_stack_b)
    {
        if(bigger == t_stack_b->content)
            pos_bigger == i;
        i++;
        t_stack_b = t_stack_b->next;       
    }
    size_b = i;
}

void get_shorter_a(t_stack *)
{
    t_stack *tmp;
    int i;

    tmp = t_stack;
    while (tmp)
    {
        if(shorter > tmp->content && (i >= 0 && i <= 10)
            shorter = tmp->content;
        if(shorter2 > tmp->content && (i >= (size_a - 10) && i <= size_a)
            shorter2 = tmp->content;
        tmp = tmp->next;
    }
    i = 1;
    while (t_stack * t_stack_a)
    {
        if(shorter == t_stack_a->content)
            pos_shorter == i;
        if(shorter2 == t_stack_a->content)
            pos_shorter2 == i;
        i++;
        t_stack_a = t_stack_a->next;       
    }
}


int get_value(int i, t_stack *stack, int *value)
{
    int w;
    
    w = 0;
    while(w < i)
        t_stack = t_stack->next;
    value[i] = t_stack->content;
}
*/
















/*
void    ft_tri100(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
    int indic;
    int count;
    int i;
	int var;

    i = 1;
	var = 0;
    
	while(stock->done != stock->size_all)
    {
        if (stock->done + 20 > stock->size_all)
            count = 20 - (stock->done - stock->size_all);
        else
            count = 20;
        while(count != 0)
        {
            stock->size_b = get_size(stack_b, stock);
            stock->size_a = get_size(stack_a, stock);
            printf("boucle :%d\n", i++);
            ft_crea_tab_pos(stack_a, stock);
            printf("m\n");
            nmkcoup(stock);
            printf("n\n");
            indic = checklowercoup(stock);
            printf("o\n");
            mvlowercoup(indic, stock, stack_a);
            printf("p\n");
            ft_last(stack_b, stock);
            printf("q\n");
            ft_pos_accept(stack_a, stack_b, stock);
            count--;
			ft_print_lst(*stack_b);
        }
        stock->size_a = get_size(stack_a, stock);
        ft_accept_a(stack_a, stock);
        while(stack_b)
        {
            ft_pb(stack_a, stack_b);
        }
    }
}

void ft_accept_a(t_stack **stack_a, t_stock *stock)
{
    int pos;


    ft_checkaccept(stack_a, stock);
    pos = stock->tab2[stock->var_tabcheck];
    if (pos > stock->size_a / 2)
    {
        while(pos < stock->size_a)
        {
            ft_rra(stack_a);
            pos++;
        }
    }
    else if (pos < stock->size_a / 2)
    {
        while(pos + 1 > 0)
        {
            ft_ra(stack_a);
            pos--;
        }
    }
}

void	ft_checkaccept(t_stack **stack_a, t_stock *stock)
{
    int w;
    int x;
    int i;
    int check;
    int check_pos;
    t_stack *tmp;
    
    w = 20 * stock->checkaccepta;
    x = 0;
    i = 0;
	stock->var_tabcheck = w - 1;

    if (w > stock->size_a)
        w = stock->size_a;
    while(w)
    {
        check = INT_MAX;
        tmp = (*stack_a);
        while (tmp)
        {
            if (check > tmp->content && ft_checktab(tmp->content, stock->tab) != 0)
            {
                check = tmp->content;
                check_pos = i;
            }
            tmp = tmp->next;
            i++;
        }
        stock->tab[x] = check;
        stock->tab2[x] = check_pos;
        x++;
        w--;
    }
    stock->checklast = stock->tab[x];
    stock->checkaccepta += 1;
}

void mvlowercoup(int indic, t_stock *stock, t_stack **stack_a)
{
    int coups;

    printf("1\n");
    printf("%d\n", indic);
    coups = stock->tab2[indic];
    if(stock->tab3[indic] == 0)
    {
        while(coups > 0)
        {
            ft_rra(stack_a);
            coups--;
        }
    }
    else
    {
        while(coups > 0)
        {
            ft_ra(stack_a);
            coups--;
        }
    }
}

void ft_crea_tab_pos(t_stack **stack_a, t_stock *stock)
{
    int w;
    int x;
    int i;
    int check;
    int check_pos;
    t_stack *tmp;
    
    w = 20;
    x = 0;
    i = 0;
    stock->done += w;
    if (stock->done > stock->size_a)
    {
        w = w - (stock->done - stock->size_a);
        stock->done = stock->size_a;
    }
    ft_print_lst(*stack_a);
    while(w)
    {
        i = 0;
        check = INT_MAX;
        tmp = (*stack_a);
        while (tmp)
        {
            if (check > tmp->content && ft_checktab(tmp->content, stock->tab) != 0)
            {
                check = tmp->content;
                check_pos = i;
            }
            tmp = tmp->next;
            i++;
        }
        stock->tab[x] = check;
        stock->tab2[x] = check_pos;
        x++;
        w--;
    }
    printf("valeur tab = %d\n", stock->tab[1]);
    printf("valeur tab2 = %d\n", stock->tab2[1]);
    stock->checklast = stock->tab[x];
}

int ft_checktab(int valeur, int *tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        if (tab[i] == valeur)
            return(0);
        i++;
    }
    return(1);
}

void nmkcoup(t_stock *stock)
{
    int w;
    int x;

    x = 0;
    w = 20;
    if(stock->size_a < 20)
        w = stock->size_a;
    while(w)
    {
        if(stock->size_a - stock->tab2[x] > stock->tab2[x] - 1) // 1 = ra 
        {
            stock->tab2[x] = stock->tab2[x] - 1;
            stock->tab3[x] = 1;
        }
        else // 0 = rra
        {
            stock->tab2[x] = (stock->size_a - stock->tab2[x] + 1);
            stock->tab3[x] = 0;
        }
		printf("tab mk = %d\n", stock->tab2[x]);
		x++;
        w--;
    }
}

int checklowercoup(t_stock *stock)
{
    int i;
    int check;
    int indic;

    check = INT_MAX;
    i = 0;
    while(stock->tab2[i])
    {
        if(check > stock->tab2[i])
        {
            check = stock->tab2[i];
            printf("i = %d\n", i);
            indic = i;
        }
        i++;
    }
    return(indic);
}


void ft_last(t_stack **stack_b, t_stock *stock)
{
	t_stack *tmp;

	tmp = (*stack_b);
	if (*stack_b == NULL)
		return ;
	while(tmp && tmp->next)
		tmp = tmp->next;
	stock->lastb = tmp->content;
}

void ft_pos_accept(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
	int i;
	int value;
	int pos_accept;
	t_stack *tmp;

	value = (*stack_a)->content;
	tmp = (*stack_b);
	i = 1;
	if (*stack_b == NULL || stock->size_b == 1 
		|| (value > (*stack_b)->content && value > stock->lastb))
	{
		ft_pb(stack_a, stack_b);
		return ;
	}
	if (value < (*stack_b)->content && value < stock->lastb)
	{
		ft_pb(stack_a, stack_b);
		ft_rb(stack_b);
		return ;
	}
	while(tmp)
	{
		if(value < tmp->content && value > tmp->next->content)
			pos_accept = i;
		tmp = tmp->next;
		i++;
	}
	if(pos_accept > (stock->size_b / 2))
	{
		while (pos_accept < stock->size_b)
		{
			pos_accept++;
			ft_rrb(stack_b);
		}
	}
	else if (pos_accept < (stock->size_b / 2))
	{
		while (pos_accept > 0)
		{
			pos_accept--;
			ft_rb(stack_b);
		}
	}
	ft_pb(stack_a, stack_b);
}











ft_tri100test()
{
    get_size_a();
    mkchunk();
    ft_chunk();
	ft_pos_accept();
}


mkchunk(t_stock *stock)
{
    int chunk_size;

    if(stock->size_a > 5 && stock->size_a <= 100)
    {
        chunk_size =  20;
    }
    else if(size_a > 100)
    {
        chunk_size = 25;
    }
}

void ft_chunk(t_stock *stock, t_stack **stack_a)
{
    int i;
    int check;
    t_stack *tmp;
    int verif;
    int pos;

    verif = 150;
    while(stock->chunk_size > i)
    {
        i = 0;
        check = INT_MAX;
        tmp = (*stack_a);
        while (tmp)
        {
            if (check > tmp->content && checkcp(i, stock) < verif)
            {
                check = tmp->content;
                verif = checkcp(i, stock);
            }
            tmp = tmp->next;
            i++;
        }
    }
    pos = ft_checkpos(check, stack_a);
    ft_mvfirst(stock, pos, stack_a);
}

void ft_mvfirst(t_stock *stock, int pos, t_stack **stack_a)
{
    if(pos > stock->size_a/2)
    {
        while((stock->size_a + 1) - pos)
        {
            ft_rra(stack_a);
            pos++;
        }
    }
    else
        while(pos)
        {
            ft_ra(stack_a);
            pos--;
        }
    }
}

int ft_checkpos(int check, t_stack **stack_a)
{
    int i;
    t_stack *tmp;
    int pos;

    tmp = (*stack_a);
    while (tmp)
    {
        if (tmp->content == check)
            pos = i;
        i++;
        tmp = tmp->next;
    }
    return(pos);
}
int checkcp(int i, t_stock *stock)
{
    if(i > stock->size_a /2)
        i = i - stock->size_a/2;
    return(i);
}
*/
// Limit fin de chunk pour comparer au premier passage