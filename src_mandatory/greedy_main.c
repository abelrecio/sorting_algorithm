/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:22:16 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/24 17:43:50 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back_greedy(t_list **a, t_list **b)
{
	t_cost	cheapest;

	while (*b)
	{
		cheapest = find_cheapest(*a, *b);
		move(a, b, cheapest);
	}
}

void	greedy_sort(t_list **a, t_list **b)
{
	if (!a || !*a)
		return ;
	if (is_sorted(*a))
		return ;
	push_to_b_by_ranges(a, b);
	if (ft_lstsize(*a) == 3)
		sort_three(a);
	push_back_greedy(a, b);
	rotate_to_min(a);
}
