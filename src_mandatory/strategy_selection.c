/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_selection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 01:01:40 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/21 01:01:41 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_strategy_costs(t_cost *cost, int costs[4])
{
	if (cost->ra_moves >= cost->rb_moves)
		costs[0] = cost->ra_moves;
	else
		costs[0] = cost->rb_moves;
	if (cost->rra_moves >= cost->rrb_moves)
		costs[1] = cost->rra_moves;
	else
		costs[1] = cost->rrb_moves;
	costs[2] = cost->ra_moves + cost->rrb_moves;
	costs[3] = cost->rra_moves + cost->rb_moves;
}

static void	select_cheapest_strategy(t_cost *cost, int costs[4])
{
	int	i;

	cost->total = costs[0];
	cost->strategy = 1;
	i = 1;
	while (i < 4)
	{
		if (costs[i] < cost->total)
		{
			cost->total = costs[i];
			cost->strategy = i + 1;
		}
		i++;
	}
}

void	find_best_strategy(t_cost *cost)
{
	int	costs[4];

	calculate_strategy_costs(cost, costs);
	select_cheapest_strategy(cost, costs);
}
