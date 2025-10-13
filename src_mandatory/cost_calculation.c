#include "push_swap.h"

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

t_cost	calculate_cost(t_list *stack_a, t_list *stack_b, int pos_b)
{
	t_cost	cost;
	int		val_b;
	int		size_a;
	int		size_b;
	t_list	*tmp;
	int		i;
	int		cost_rr;
	int		cost_rrr;
	int		cost_mixed1;
	int		cost_mixed2;

	tmp = stack_b;
	i = 0;
	while (i < pos_b && tmp)
	{
		tmp = tmp->next;
		i++;
	}
	val_b = get_value(tmp);
	cost.pos_b = pos_b;
	cost.pos_a = find_target_pos_in_a(stack_a, val_b);
	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	cost.ra_moves = cost.pos_a;
	cost.rra_moves = size_a - cost.pos_a;
	cost.rb_moves = pos_b;
	cost.rrb_moves = size_b - pos_b;
	if (cost.ra_moves >= cost.rb_moves)
		cost_rr = cost.ra_moves;
	else
		cost_rr = cost.rb_moves;
	if (cost.rra_moves >= cost.rrb_moves)
		cost_rrr = cost.rra_moves;
	else
		cost_rrr = cost.rrb_moves;
	cost_mixed1 = cost.ra_moves + cost.rrb_moves;
	cost_mixed2 = cost.rra_moves + cost.rb_moves;
	cost.total = cost_rr;
	cost.strategy = 1;
	if (cost_rrr < cost.total)
	{
		cost.total = cost_rrr;
		cost.strategy = 2;
	}
	if (cost_mixed1 < cost.total)
	{
		cost.total = cost_mixed1;
		cost.strategy = 3;
	}
	if (cost_mixed2 < cost.total)
	{
		cost.total = cost_mixed2;
		cost.strategy = 4;
	}
	return (cost);
}
