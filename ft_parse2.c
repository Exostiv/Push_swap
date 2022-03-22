/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:08:18 by tnicoue           #+#    #+#             */
/*   Updated: 2022/03/01 10:35:09 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verifint(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->content < -2147483648)
			return (0);
		if (tmp->content > 2147483647)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_check_order(t_stack *stack_a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->next && tmp->content > tmp->next->content)
			i = 1;
		tmp = tmp->next;
	}
	return (i);
}
