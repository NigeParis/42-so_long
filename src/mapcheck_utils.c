/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:57:15 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/13 11:13:46 by nrobinso         ###   ########.fr       */
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

int	is_game_object(t_data *data, char c)
{
	int	count;
	int	i;
	int	y;

	count = 0;
	i = 0;
	y = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][y] != '\0')
		{
			if (data->map[i][y] == c)
				count++;
			y++;	
		}
		y = 0;
		i++;
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