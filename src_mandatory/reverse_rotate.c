/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:59:37 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/24 17:49:47 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_list **stack_a, int silent)
{
	reverse_rotate(stack_a);
	if (!silent)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int silent)
{
	reverse_rotate(stack_b);
	if (!silent)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, int silent)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (!silent)
		write(1, "rrr\n", 4);
}
