/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:41:33 by tnicoue           #+#    #+#             */
/*   Updated: 2022/03/01 14:56:07 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_onsenfou(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

void	free_split(char **cpy_argv)
{
	char	**tmp;

	tmp = cpy_argv;
	while (*tmp)
		free(*tmp++);
	free(cpy_argv);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stock	stock;

	stack_a = NULL;
	if (ft_chklist(argc, argv) == 0)
		return (0);
	if (ft_mklist(&stack_a, argc, argv) == 0)
		return (0);
	if (ft_verifclean(stack_a) == 0)
		return (0);
	if (ft_check_order(stack_a) == 0)
		return (0);
	ft_init_struct(&stack_a, &stock);
	direction(&stack_a, &stack_b, &stock);
}
