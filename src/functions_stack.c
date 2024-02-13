/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:28:50 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/08 15:28:51 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_sorted(t_node **stack)
{
	t_node	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	stack_init(t_node **stack, char **ptr)
{
	int		i;
	t_node	*temp;
	t_node	*create;

	i = 0;
	*stack = NULL;
	while (ptr[i])
	{
		create = (t_node *)malloc(sizeof(t_node));
		if (!create)
			return ;
		create->value = ft_atol(ptr[i]);
		create->next = NULL;
		if (i == 0)
		{
			*stack = create;
			temp = create;
		}
		else
		{
			temp->next = create;
			temp = create;
		}
		i++;
	}
}

int	stack_size(t_node **stack)
{
	int		count;
	t_node	*temp;

	temp = *stack;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	mini_sort(t_node **a)
{
	t_node	*highest;

	highest = get_highest(*a);
	if (*a == highest)
		ra(a, 1);
	else if ((*a)->next == highest)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	ft_free(t_node **stack)
{
	t_node	*temp;
	t_node	*dummy;

	temp = *stack;
	while (temp)
	{
		dummy = temp->next;
		free(temp);
		temp = dummy;
	}
	*stack = NULL;
}
