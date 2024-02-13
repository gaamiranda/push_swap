/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:47:12 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/13 11:47:14 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*linha;
	int			i;

	linha = NULL;
	i = 0;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		while (buf[i])
			buf[i] = '\0';
		return (NULL);
	}
	while (buf[0] || read(fd, buf, BUFFER_SIZE) > 0)
	{
		linha = ft_help(linha, buf);
		if (ft_bufclear(buf) == 1)
			break ;
	}
	return (linha);
}
