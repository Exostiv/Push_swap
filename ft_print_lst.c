/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:40:42 by tnicoue           #+#    #+#             */
/*   Updated: 2022/02/02 10:02:55 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_lst(t_stack *stack)
{
	t_stack	*tmp;
	int	i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		printf("tmp->content [%d] = %d, \n", i, tmp->content);
		tmp = tmp->next;
		i++;
	}
}
