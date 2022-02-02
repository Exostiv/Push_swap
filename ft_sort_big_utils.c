/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:09:19 by tnicoue           #+#    #+#             */
/*   Updated: 2022/02/02 14:57:31 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_biggerchunk_a(t_stack **stack_a, t_stock *stock)
{
    int w;
    int check;
    t_stack *tmp;
    int tab[20];
    int i;

    i = 0;
    w = stock->chunk_size;
    if(stock->chunk_size > stock->size_a)
        w = stock->size_a;
    while(w)
    {
        check = INT_MAX;
        tmp = (*stack_a);
        while (tmp)
        {
            if (check > tmp->content && ft_checktab(tmp->content, tab) != 0)
            {
                check = tmp->content;
            }
            tmp = tmp->next;
        }
        w--;
        tab[i] = check;
        i++;
    }
    stock->bigger_chunk = tab[i];
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