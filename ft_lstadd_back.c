/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:39:45 by tnicoue           #+#    #+#             */
/*   Updated: 2022/03/03 10:27:10 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*last;
	t_stack	*tmp;

	tmp = *alst;
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			last = tmp;
			last->next = new;
		}
	}
}

void	ft_init_struct(t_stack **stack_a, t_stock *stack)
{
	stack->chunk_size = 0;
	stack->bigger = INT_MIN;
	stack->shorter = INT_MAX;
	stack->shorter2 = INT_MAX;
	stack->pos_shorter = 0;
	stack->pos_shorter2 = 0;
	stack->size_b = 0;
	stack->size_a = 0;
	stack->lastb = 0;
	stack->var_tabcheck = 0;
	stack->pos_bigger = 0;
	stack->done = 0;
	stack->checklast = 0;
	stack->pos = 0;
	stack->pos2 = INT_MIN;
	stack->oldbig = INT_MIN;
	stack->done = 0;
	get_size_a(stack_a, stack);
}
