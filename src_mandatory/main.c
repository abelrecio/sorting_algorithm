/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:40:28 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/13 13:28:20 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list			*stack_a;
	t_list			*stack_b;
	struct s_arena	arena;

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
	if (!arena.data)
		return (1);
	if (!parse_arguments(argc, argv, &arena, &stack_a))
		return (1);
	greedy_sort(&stack_a, &stack_b);
	arena_free(&arena);
	return (0);
}
