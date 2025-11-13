/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves_basic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:55:10 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/24 17:42:52 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_min(t_list **stack_a)
{
	int	min;
	int	position;
	int	size;

	min = get_min(*stack_a);
	position = find_position(*stack_a, min);
	size = ft_lstsize(*stack_a);
	if (position <= size / 2)
	{
		while (get_value(*stack_a) != min)
			ra(stack_a, 0);
	}
	else
	{
		while (get_value(*stack_a) != min)
			rra(stack_a, 0);
	}
}

void	move(t_list **stack_a, t_list **stack_b, t_cost cost)
{
	if (cost.strategy == 1)
		execute_rr(stack_a, stack_b, cost);
	else if (cost.strategy == 2)
		execute_rrr(stack_a, stack_b, cost);
	else
		execute_mixed(stack_a, stack_b, cost, cost.strategy);
	pa(stack_a, stack_b, 0);
}
