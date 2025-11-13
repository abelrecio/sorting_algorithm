/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 21:57:57 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/25 17:49:48 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_mandatory/push_swap.h"

static int	execute_operation(char *op, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(stack_a, 1);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(stack_b, 1);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(stack_a, stack_b, 1);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(stack_a, stack_b, 1);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(stack_a, stack_b, 1);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(stack_a, 1);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(stack_b, 1);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 1);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(stack_a, 1);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(stack_b, 1);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 1);
	else
		return (0);
	return (1);
}

static int	read_and_execute(t_list **stack_a, t_list **stack_b, int *count)
{
	char	*line;

	*count = 0;
	line = get_next_line(0);
	while (line)
	{
		if (!execute_operation(line, stack_a, stack_b))
		{
			free(line);
			write(2, "Error\n", 6);
			return (0);
		}
		(*count)++;
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

static void	print_result(int sorted, int moves)
{
	if (sorted)
	{
		write(1, "OK: ", 4);
		ft_putnbr_fd(moves, 1);
		write(1, " moves\n", 7);
	}
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	t_list			*stack_a;
	t_list			*stack_b;
	struct s_arena	arena;
	int				moves;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	arena = arena_create(16384);
	if (argc == 2)
	{
		argc = count_new_arg(argv[1]) + 1;
		argv = arena_split(argv[1], ' ', &arena);
	}
	if (!parse_arguments(argc, argv, &arena, &stack_a))
		return (1);
	if (!read_and_execute(&stack_a, &stack_b, &moves))
	{
		arena_free(&arena);
		return (1);
	}
	print_result(is_sorted(stack_a) && !stack_b, moves);
	arena_free(&arena);
	return (0);
}
