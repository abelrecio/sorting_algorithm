/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves_special.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:45:20 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/24 18:09:58 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_n_times(t_list **stack, void (*rotate_fn)(t_list **, int),
		int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rotate_fn(stack, 0);
		i++;
	}
}

static void	rotate_both_n_times(t_list **a, t_list **b, void (*fn)(t_list **,
			t_list **, int), int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		fn(a, b, 0);
		i++;
	}
}

void	execute_rr(t_list **stack_a, t_list **stack_b, t_cost cost)
{
	int	sim;

	if (cost.ra_moves < cost.rb_moves)
		sim = cost.ra_moves;
	else
		sim = cost.rb_moves;
	rotate_both_n_times(stack_a, stack_b, rr, sim);
	rotate_n_times(stack_a, ra, cost.ra_moves - sim);
	rotate_n_times(stack_b, rb, cost.rb_moves - sim);
}

void	execute_rrr(t_list **stack_a, t_list **stack_b, t_cost cost)
{
	int	sim;

	if (cost.rra_moves < cost.rrb_moves)
		sim = cost.rra_moves;
	else
		sim = cost.rrb_moves;
	rotate_both_n_times(stack_a, stack_b, rrr, sim);
	rotate_n_times(stack_a, rra, cost.rra_moves - sim);
	rotate_n_times(stack_b, rrb, cost.rrb_moves - sim);
}

void	execute_mixed(t_list **stack_a, t_list **stack_b, t_cost cost,
		int strategy)
{
	if (strategy == 3)
	{
		rotate_n_times(stack_a, ra, cost.ra_moves);
		rotate_n_times(stack_b, rrb, cost.rrb_moves);
	}
	else
	{
		rotate_n_times(stack_a, rra, cost.rra_moves);
		rotate_n_times(stack_b, rb, cost.rb_moves);
	}
}
