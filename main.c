/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:38:04 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/08/08 18:16:52 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_stacks
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		*stack_size;
}	t_stacks;

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_ra(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	setup_stacks(int argc, char **argv, t_stacks *stacks)
{
	char	**args;

	*(stacks->stack_b) = NULL;
	if (argc == 2)
	{
		args = split_args(argv[1]);
		if (!is_correct_input(args, 0))
			exit_error(NULL, NULL);
		*(stacks->stack_a) = fill_stack_values(size_numbers(args) - 1, args, 0);
		free_split(args);
		*(stacks->stack_size) = get_stack_size(*(stacks->stack_a));
	}
	else
	{
		if (!is_correct_input(argv, 1))
			exit_error(NULL, NULL);
		*(stacks->stack_a) = fill_stack_values(argc, argv, 1);
		*(stacks->stack_size) = get_stack_size(*(stacks->stack_a));
	}
	assign_index(*(stacks->stack_a), *(stacks->stack_size) + 1);
}

int	main(int argc, char **argv)
{
	t_stacks		stacks;
	int				stack_size;
	t_stack			*stack_a;
	t_stack			*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stacks.stack_a = &stack_a;
	stacks.stack_b = &stack_b;
	stacks.stack_size = &stack_size;
	setup_stacks(argc, argv, &stacks);
	push_swap(stacks.stack_a, stacks.stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
