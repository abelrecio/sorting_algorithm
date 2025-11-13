/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:40:59 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/24 17:46:01 by abrecio-         ###   ########.fr       */
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
