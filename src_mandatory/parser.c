/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:12:01 by abrecio-          #+#    #+#             */
/*   Updated: 2025/11/14 18:37:44 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_new_arg(char *nums)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (nums[i] != '\0')
	{
		while (nums[i] == ' ' && nums[i] != '\0')
			i++;
		if (nums[i] != '\0')
			result++;
		while (nums[i] != ' ' && nums[i] != '\0')
			i++;
	}
	return (result);
}

int	is_rep(t_list *stack_a, int *num)
{
	while (stack_a)
	{
		if (get_value(stack_a) == *num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	create_node(t_arena *arena, t_list **stack_a, char *arg)
{
	int		*num;
	long	temp;
	t_list	*node;

	num = arena_alloc(arena, sizeof(int));
	if (!num)
		return (0);
	if (!is_valid_number(arg))
		return (0);
	temp = ft_atol(arg);
	if (temp < INT_MIN || temp > INT_MAX)
		return (0);
	*num = (int)temp;
	if (is_rep(*stack_a, num))
		return (0);
	node = arena_alloc(arena, sizeof(t_list));
	if (!node)
		return (0);
	node->content = num;
	node->next = NULL;
	ft_lstadd_back(stack_a, node);
	return (1);
}

int	parse_arguments(int argc, char *argv[], t_arena *arena,
		t_list **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!create_node(arena, stack_a, argv[i]))
		{
			write(2, "Error\n", 6);
			arena_free(arena);
			return (0);
		}
		i++;
	}
	return (1);
}
