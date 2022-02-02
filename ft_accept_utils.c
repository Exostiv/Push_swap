/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accept_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:34:26 by tnicoue           #+#    #+#             */
/*   Updated: 2022/02/02 16:08:35 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_mvmax(t_stack **a, t_stack **b, t_stock *stock, int max)
{
    t_stack *tmp;
    int i;
    int pos;

    tmp = (*b);
    i = 0;
    while(tmp)
    {
        if (tmp->content == max)
            pos = i;
        tmp = tmp->next;
        i++;
    }
    ft_rotate_max(a, b, stock, pos, max);
}

void ft_rotate_max(t_stack **a, t_stack **b, t_stock *stock, int pos, int max)
{
    if(pos > (stock->size_b /2) + 1)\
    {
        while(pos < stock->size_b)
        {
            pos++;
            ft_rrb(b);
        }
    }
    else if(pos <= (stock->size_b /2) + 1)
    {
        while(pos > 0)
        {
            pos--;
            ft_rb(b);
        }
    }
    ft_pb(a, b, stock);
    if((*b)->content < max)
        ft_rb(b);
}