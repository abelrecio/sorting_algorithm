/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:59:42 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/24 17:39:38 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_list **stack_a, int silent)
{
	rotate(stack_a);
	if (!silent)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int silent)
{
	rotate(stack_b);
	if (!silent)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int silent)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!silent)
		write(1, "rr\n", 3);
}
