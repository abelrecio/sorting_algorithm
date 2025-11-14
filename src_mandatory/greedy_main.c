/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:22:16 by abrecio-          #+#    #+#             */
/*   Updated: 2025/11/14 19:55:54 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back_greedy(t_list **stack_a, t_list **stack_b)
{
	t_cost	cheapest;

	while (*stack_b)
	{
		cheapest = find_cheapest(*stack_a, *stack_b);
		move(stack_a, stack_b, cheapest);
	}
}

void	greedy_sort(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	if (is_sorted(*stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 5)
	{
		sort_five(stack_a, stack_b);
		return ;
	}
	push_to_b_by_ranges(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	push_back_greedy(stack_a, stack_b);
	rotate_to_min(stack_a);
}
