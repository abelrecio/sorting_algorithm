/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:40:59 by abrecio-          #+#    #+#             */
/*   Updated: 2025/11/14 19:56:28 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = get_value(*stack_a);
	num2 = get_value((*stack_a)->next);
	num3 = get_value((*stack_a)->next->next);
	if (num1 < num2 && num2 < num3)
		return ;
	if (num1 > num2 && num2 < num3 && num1 < num3)
		sa(stack_a, 0);
	else if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		sa(stack_a, 0);
		rra(stack_a, 0);
	}
	else if (num1 > num2 && num1 > num3 && num2 < num3)
		ra(stack_a, 0);
	else if (num1 < num2 && num1 > num3 && num2 > num3)
		rra(stack_a, 0);
	else if (num1 < num2 && num2 > num3 && num1 < num3)
	{
		sa(stack_a, 0);
		ra(stack_a, 0);
	}
}

static void	move_five(t_list **stack_a)
{
	int	size;
	int	position;

	size = ft_lstsize(*stack_a);
	position = find_position(*stack_a, get_min(*stack_a));
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ra(stack_a, 0);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			rra(stack_a, 0);
			position++;
		}
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 2;
	while (i)
	{
		move_five(stack_a);
		pb(stack_a, stack_b, 0);
		i--;
	}
	sort_three(stack_a);
	pa(stack_a, stack_b, 0);
	pa(stack_a, stack_b, 0);
}
