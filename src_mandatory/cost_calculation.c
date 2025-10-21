/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 01:00:51 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/21 01:06:22 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_value_at_pos(t_list *stack, int pos)
{
	int	i;

	i = 0;
	while (i < pos && stack)
	{
		stack = stack->next;
		i++;
	}
	return (get_value(stack));
}

static void	calculate_moves(t_cost *cost, int size_a, int size_b)
{
	cost->ra_moves = cost->pos_a;
	cost->rra_moves = size_a - cost->pos_a;
	cost->rb_moves = cost->pos_b;
	cost->rrb_moves = size_b - cost->pos_b;
}

t_cost	calculate_cost(t_list *stack_a, t_list *stack_b, int pos_b)
{
	t_cost	cost;
	int		val_b;
	int		size_a;
	int		size_b;

	val_b = get_value_at_pos(stack_b, pos_b);
	cost.pos_b = pos_b;
	cost.pos_a = find_target_pos_in_a(stack_a, val_b);
	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	calculate_moves(&cost, size_a, size_b);
	find_best_strategy(&cost);
	return (cost);
}

t_cost	find_cheapest(t_list *stack_a, t_list *stack_b)
{
	t_cost	cost;
	t_cost	min_cost;
	int		i;
	int		size;

	size = ft_lstsize(stack_b);
	min_cost = calculate_cost(stack_a, stack_b, 0);
	i = 1;
	while (i < size)
	{
		cost = calculate_cost(stack_a, stack_b, i);
		if (cost.total < min_cost.total)
			min_cost = cost;
		i++;
	}
	return (min_cost);
}
