/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 01:01:25 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/21 01:01:26 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_value(t_list *node)
{
	return (*(int *)node->content);
}

int	get_max(t_list *stack)
{
	int	max;

	max = get_value(stack);
	while (stack)
	{
		if (max < get_value(stack))
			max = get_value(stack);
		stack = stack->next;
	}
	return (max);
}

int	get_min(t_list *stack)
{
	int	min;

	min = get_value(stack);
	while (stack)
	{
		if (min > get_value(stack))
			min = get_value(stack);
		stack = stack->next;
	}
	return (min);
}

//porque el último igual es null e itero de forma confusa

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if ((get_value(stack) > get_value(stack->next)))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_position(t_list *stack, int val)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		if (get_value(stack) == val)
			return (counter);
		stack = stack->next;
		counter++;
	}
	return (-1);
}
