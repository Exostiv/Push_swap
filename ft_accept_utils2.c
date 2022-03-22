/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accept_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:30:25 by tnicoue           #+#    #+#             */
/*   Updated: 2022/03/03 10:44:54 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_m(int a, void (*pf)(t_stack **s), t_stack **st)
{
	while (a)
	{
		pf(st);
		a--;
	}
}

void	ft_checkb(t_stack **stack_b, t_stock *stock)
{
	if (stack_b)
	{
		if (stock->size_b > 2)
			stock->lastb = ft_lastb(stack_b);
		stock->biggerb = ft_bigger_b(stack_b);
		stock->lowerb = ft_lower_b(stack_b);
	}
}
