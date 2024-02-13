/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:47:25 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/13 11:47:26 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include "../include/push_swap.h"
# include <fcntl.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_help(char *str, char *buf);
char	*ft_nlcheck(char *str);
int		ft_bufclear(char *buf);
void	process_args(int argc, char **argv, char ***args, int *allocated);
void	check_commands(char *command, t_node **a, t_node **b);
void	error(t_node **a, t_node **b);
int		ft_strcmp(char *s1, char *s2);

#endif
