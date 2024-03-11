/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:57:15 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/11 16:37:09 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	ft_ismap_rectangle(t_data *data)
{

	int linelen;
	int	i;
	int y;	

	i = 0;
	y = 0;
	linelen = ft_strlen(data->map[i]);
	while (data->map[i] != NULL)
	{
		y = ft_strlen(data->map[i]);
		if (y != linelen)
			return (1);
		i++;
	}
	return (0);
}

int	ft_ismap_border(t_data *data)
{
	int	i;
	int	lastline;
	int	endlinechar;

	i = 0;
	lastline = 0;
	endlinechar = ft_strlen(data->map[0]) - 1;
	while (data->map[lastline] != NULL)
		lastline++;

	while (data->map[0][i] != '\0')
	{
		if (data->map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (data->map[lastline - 1][i] != '\0')
	{
		if (data->map[lastline - 1][i] != '1')
			return (1);
		i++;
	}

	i = 1;
	while (i < lastline - 1)
	{
		if (data->map[i][0] != '1' || data->map[i][endlinechar] != '1')
			return (1);
		i++;
	}

	return (0);
}