/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortchoose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:41:45 by tnicoue           #+#    #+#             */
/*   Updated: 2022/02/02 10:37:56 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    direction(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
    get_size_a(stack_a, stock);
    if (stock->size_a <= 3)
        choose_sort_short(stack_a, stock);
    else
        choose_sort_big(stack_a, stack_b, stock);
}

void choose_sort_short(t_stack **stack_a, t_stock *stack)
{
    if(stack->size_a == 2)
        ft_tri2(stack_a);
    else if(stack->size_a == 3)
        ft_tri3(stack_a);
}

void choose_sort_big(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
    if(stock->size_a == 4)
        ft_tri4(stack_a, stack_b, stock);
    else if(stock->size_a == 5)
        ft_tri5(stack_a, stack_b, stock);
   /* else if(stock->size_a <= 6)
        ft_tribig(stack_a, stack_b, stock);
    else if (stock->size_all > 100 && stock->size_all <= 500)
        ft_big_sort500(stack_a, stack_b, stock);*/
}

void get_size_a(t_stack **stack_a, t_stock *stock)
{
    int i;
    t_stack *tmp;

    i = 0;
    tmp = (*stack_a);
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    stock->size_a = i;
}