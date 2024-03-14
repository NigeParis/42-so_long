/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:57:15 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/14 10:18:06 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_ismap_rectangle(t_data *data)
{
	int	linelen;
	int	x;
	int	y;	

	x = 0;
	y = 0;
	linelen = ft_strlen(data->map[x]);
	while (data->map[x] != NULL)
	{
		y = ft_strlen(data->map[x]);
		if (y != linelen)
			return (1);
		x++;
	}
	return (0);
}

int	ft_firstlastline_check(t_data *data, int x, int y)
{
	while (data->map[x][y] != '\0')
	{
		if (data->map[x][y] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	ft_ismap_border(t_data *data)
{
	int	x;
	int	lastline;
	int	endlinechar;

	x = 0;
	lastline = 0;
	endlinechar = ft_strlen(data->map[0]) - 1;
	while (data->map[lastline] != NULL)
		lastline++;
	if (ft_firstlastline_check(data, 0, x))
		return (1);
	if (ft_firstlastline_check(data, lastline - 1, x))
		return (1);
	x = 1;
	while (x < lastline - 1)
	{
		if (data->map[x][0] != '1' || data->map[x][endlinechar] != '1')
			return (1);
		x++;
	}
	return (0);
}

int	is_game_object(t_data *data, char c)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	x = 0;
	y = 0;
	while (data->map[x] != NULL)
	{
		while (data->map[x][y] != '\0')
		{
			if (data->map[x][y] == c)
				count++;
			y++;	
		}
		y = 0;
		x++;
	}
	return (count);
}

int	is_items_known(char c, char *str)
{
	int	len;
	int	i;
	int	found;

	len = ft_strlen(str);
	i = 0;
	found = 0;
	while (i < len)
	{
		if (c == str[i])
			found++;
		i++;
	}
	return (found);
}