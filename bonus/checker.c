/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:47:20 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/13 11:47:21 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	error(t_node **a, t_node **b)
{
	ft_free(a);
	ft_free(b);
	write(1, "Error\n", 6);
	exit(2);
}

void	check_commands(char *command, t_node **a, t_node **b)
{
	if (!ft_strcmp(command, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(command, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(command, "pb\n"))
		pb(a, b, 0);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, 0);
	else
		error(a, b);
}

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
