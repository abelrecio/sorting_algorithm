/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:40:59 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/21 00:51:22 by abrecio-         ###   ########.fr       */
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
		sa(stack_a);
	else if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (num1 > num2 && num1 > num3 && num2 < num3)
		ra(stack_a);
	else if (num1 < num2 && num1 > num3 && num2 > num3)
		rra(stack_a);
	else if (num1 < num2 && num2 > num3 && num1 < num3)
	{
		sa(stack_a);
		ra(stack_a);
	}
}
