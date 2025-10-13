#include "push_swap.h"

int	get_value(t_list *node)
{
	// esperemos que nunca sea null y que esté metiendo los números bien
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

int	is_sorted(t_list *stack)
{
	while (stack->next)
	//porque el último igual es null e itero de forma confusa
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
