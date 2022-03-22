/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:46:42 by tnicoue           #+#    #+#             */
/*   Updated: 2022/03/01 10:33:38 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tri2(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a);
}

void	ft_tri3(t_stack **stack_a)
{
	if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		ft_rra(stack_a);
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
		ft_ra(stack_a);
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
		ft_sa(stack_a);
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
}
