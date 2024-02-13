/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:07:14 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/13 14:07:15 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_help1(t_node **stack_a, t_node **stack_b)
{
	char	*get_command;
	int		len;

	len = stack_size(stack_a);
	get_command = get_next_line(0);
	while (get_command)
	{
		check_commands(get_command, stack_a, stack_b);
		free(get_command);
		get_command = get_next_line(0);
	}
	free(get_command);
	if (list_sorted(stack_a) && stack_size(stack_a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;
	int		allocated;

	stack_a = NULL;
	stack_b = NULL;
	allocated = 0;
	if (argc < 2 || (argc == 2 && argv[1] == NULL))
		return (-1);
	process_args(argc, argv, &args, &allocated);
	stack_init(&stack_a, args);
	ft_help1(&stack_a, &stack_b);
	if (allocated)
		ft_free_args(args);
	ft_free(&stack_a);
	ft_free(&stack_b);
}
