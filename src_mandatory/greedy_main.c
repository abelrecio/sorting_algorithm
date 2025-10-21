/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:22:16 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/21 01:24:26 by abrecio-         ###   ########.fr       */
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
	write(2, "# PHASE_1_DONE\n", 15);  // Cambiar a stdout con #
	if (ft_lstsize(*a) == 3)
		sort_three(a);
	push_back_greedy(a, b);
	write(2, "# PHASE_2_DONE\n", 15);  // Cambiar a stdout con #
	rotate_to_min(a);
	write(2, "# PHASE_3_DONE\n", 15);  // Cambiar a stdout con #
}
