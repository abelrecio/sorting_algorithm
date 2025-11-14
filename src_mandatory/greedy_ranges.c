/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_ranges.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:26:03 by abrecio-          #+#    #+#             */
/*   Updated: 2025/11/13 16:13:05 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_ranges(int size, int *num_ranges, int *range_size)
{
	if (size <= 100)
		*num_ranges = 3;
	else
		*num_ranges = 11;
	*range_size = size / *num_ranges;
}

static void	handle_push_to_b(t_list **a, t_list **b, int *rotations)
{
	int	idx_top;
	int	idx_next;

	pb(a, b, 0);
	if (*b && (*b)->next)
	{
		idx_top = get_index(*b, get_value(*b));
		idx_next = get_index(*b, get_value((*b)->next));
		if (idx_next > idx_top)
			sb(b, 0);
	}
	*rotations = 0;
}

/*
static void	process_element(t_list **a, t_list **b, t_process_data data)
{
	if (data.index < data.max_index)
		handle_push_to_b(a, b, data.rotations);
	else
	{
		ra(a, 0);
		(*data.rotations)++;
	}
}

static void	push_range_to_b(t_list **a, t_list **b, int max_index, int size)
{
	int				rotations;
	t_process_data	data;

	rotations = 0;
	while (ft_lstsize(*a) > 3 && rotations < size)
	{
		data.index = get_index(*a, get_value(*a));
		data.max_index = max_index;
		data.rotations = &rotations;
		process_element(a, b, data);
	}
}
*/

static void	push_range_to_b(t_list **a, t_list **b, int max_index, int size)
{
	int	rotations;
	int	index;

	rotations = 0;
	while (ft_lstsize(*a) > 3 && rotations < size)
	{
		index = get_index(*a, get_value(*a));
		if (index < max_index)
			handle_push_to_b(a, b, &rotations);
		else
		{
			ra(a, 0);
			rotations++;
		}
	}
}

void	push_to_b_by_ranges(t_list **a, t_list **b)
{
	int	size;
	int	num_ranges;
	int	range_size;
	int	current_range;
	int	max_index;

	size = ft_lstsize(*a);
	calculate_ranges(size, &num_ranges, &range_size);
	current_range = 0;
	while (ft_lstsize(*a) > 3 && current_range < num_ranges)
	{
		max_index = (current_range + 1) * range_size;
		if (current_range == num_ranges - 1)
			max_index = size;
		push_range_to_b(a, b, max_index, size);
		current_range++;
	}
}
