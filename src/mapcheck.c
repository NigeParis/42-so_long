/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:57:15 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/11 17:24:12 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_ismap_rectangle(t_data *data)
{
	int	linelen;
	int	i;
	int	y;	

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

int	ft_firstlastline_check(t_data *data, int line, int i)
{
	while (data->map[line][i] != '\0')
	{
		if (data->map[line][i] != '1')
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
	if (ft_firstlastline_check(data, 0, i))
		return (1);
	if (ft_firstlastline_check(data, lastline - 1, i))
		return (1);
	i = 1;
	while (i < lastline - 1)
	{
		if (data->map[i][0] != '1' || data->map[i][endlinechar] != '1')
			return (1);
		i++;
	}
	return (0);
}
