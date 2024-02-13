/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:32:55 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/08 15:32:57 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	int		tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	sa(t_node **a, int control)
{
	swap(a);
	if (control)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, int control)
{
	swap(b);
	if (control)
		write(1, "sb\n", 3);
}

void	pa(t_node **a, t_node **b, int control)
{
	t_node	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (control)
		write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, int control)
{
	t_node	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (control)
		write(1, "pb\n", 3);
}
