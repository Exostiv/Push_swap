/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:45:26 by tnicoue           #+#    #+#             */
/*   Updated: 2022/02/02 10:28:11 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_tri4(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
    getlower4_5(stack_a, stock);
    mvlower4(stack_a, stack_b, stock);
    ft_tri3(stack_a);
    ft_pa(stack_a, stack_b, stock);
}

void mvlower4(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
    int i;

    i = stock->pos_shorter;
    if (i == 3)
    {
        ft_rra(stack_a);
        ft_pb(stack_a, stack_b, stock);
    }
    else
    {
        while (i != 0)
        {
            ft_ra(stack_a);
            i--;
        }
        ft_pb(stack_a, stack_b, stock);
    }
}