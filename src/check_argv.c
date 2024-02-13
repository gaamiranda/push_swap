/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:26:34 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/08 15:26:36 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	int		sinal;
	long	res;

	i = 0;
	sinal = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sinal = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sinal);
}

int	ft_check_atol(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] - 48 >= 10 || str[i] - 48 < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicates(long num, int index, char **str)
{
	int		i;
	long	temp;

	i = 0;
	while (str[i] && i < index)
	{
		temp = ft_atol(str[i]);
		if (temp == num)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_argv(char **ptr)
{
	int		i;
	long	temp;

	i = 0;
	temp = 0;
	while (ptr[i])
	{
		if (!(ft_check_atol(ptr[i])))
			return (0);
		temp = ft_atol(ptr[i]);
		if (temp < -2147483648 || temp > 2147483647)
			return (0);
		if (!(ft_check_duplicates(temp, i, ptr)))
			return (0);
		i++;
	}
	return (1);
}

void	ft_free_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
