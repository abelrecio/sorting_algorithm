/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:54:55 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/21 00:54:56 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_list *stack, int val)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (val > get_value(stack))
			index++;
		stack = stack->next;
	}
	return (index);
}

static int	find_closest_bigger(t_list *stack_a, int val_b, int *found)
{
	int	target_val;
	int	target_pos;
	int	pos;
	int	curr_val;

	target_val = 0;
	target_pos = 0;
	*found = 0;
	pos = 0;
	while (stack_a)
	{
		curr_val = get_value(stack_a);
		if (curr_val > val_b && (!(*found) || curr_val < target_val))
		{
			target_val = curr_val;
			target_pos = pos;
			*found = 1;
		}
		pos++;
		stack_a = stack_a->next;
	}
	return (target_pos);
}

int	find_target_pos_in_a(t_list *stack_a, int val_b)
{
	int	target_pos;
	int	found;

	target_pos = find_closest_bigger(stack_a, val_b, &found);
	if (!found)
		target_pos = find_position(stack_a, get_max(stack_a)) + 1;
	return (target_pos);
}
