/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:32:49 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/08 15:32:50 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_args(int argc, char **argv, char ***args, int *allocated)
{
	if (argc == 2)
	{
		*args = ft_split(argv[1], ' ');
		*allocated = 1;
	}
	else
		*args = argv + 1;
	if (!ft_check_argv(*args))
	{
		write(2, "Error\n", 6);
		if (*allocated)
			ft_free_args(*args);
		exit(-1);
	}
}

void	process_stack(t_node **stack_a, t_node **stack_b, char **args)
{
	stack_init(stack_a, args);
	if (stack_size(stack_a) == 2 && !(list_sorted(stack_a)))
		sa(stack_a, 1);
	else if (stack_size(stack_a) == 3)
		mini_sort(stack_a);
	else if (!(list_sorted(stack_a)))
		push_swap(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;
	int		allocated;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	allocated = 0;
	i = 0;
	while (argv[1] && argv[1][i] == ' ')
		i++;
	if (argc < 2 || (argc == 2 && argv[1][i] == '\0'))
		return (-1);
	process_args(argc, argv, &args, &allocated);
	process_stack(&stack_a, &stack_b, args);
	if (allocated)
		ft_free_args(args);
	ft_free(&stack_a);
}
