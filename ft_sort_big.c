/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:55:26 by tnicoue           #+#    #+#             */
/*   Updated: 2022/02/02 15:19:20 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_tribig(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
    get_size_a(stack_a, stock);
    mkchunk(stock);
    ft_chunk(stock, stack_a);
	while(stack_a)
	{
		ft_biggerchunk_a(stack_a, stock);
		ft_pos_accept(stack_a, stack_b, stock);
	}
}


void mkchunk(t_stock *stock)
{
    int chunk_size;

    if(stock->size_a > 5 && stock->size_a <= 100)
    {
        chunk_size =  20;
    }
    else if(stock->size_a > 100)
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
    
    i = 0;
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


int ft_checkpos(int check, t_stack **stack_a)
{
    int i;
    t_stack *tmp;
    int pos;

    i = 0;
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