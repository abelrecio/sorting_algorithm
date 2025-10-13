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

int	find_target_pos_in_a(t_list *stack_a, int val_b)
{
	int		target_val;
	int		target_pos;
	int		pos;
	int		found;
	int		curr_val;
	t_list	*original;

	target_val = 0;
	target_pos = 0;
	found = 0;
	original = stack_a;
	pos = 0;
	while (stack_a)
	{
		curr_val = get_value(stack_a);
		if (curr_val > val_b && (!found || curr_val < target_val))
		{
			target_val = curr_val;
			target_pos = pos;
			found = 1;
		}
		pos++;
		stack_a = stack_a->next;
	}
	if (!found)
		target_pos = find_position(original, get_max(original)) + 1;
	return (target_pos);
}
