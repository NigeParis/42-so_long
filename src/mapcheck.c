/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:40:57 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/14 18:45:44 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_items(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[x] != NULL)
	{
		while (data->map[x][y] != '\0')
		{
			if (!is_items_known(data->map[x][y], "PCE01"))
				return (1);
			y++;
		}
		y = 0;
		x++;
	}	
	return (0);
}

int	mapcheck(t_data *data)
{
	if (ft_ismap_rectangle(data))
		return (ft_putstr_fd("Error\nnot a Rectangle", 1), 1);
	if (ft_ismap_border(data))
		return (ft_putstr_fd("Error\nBorder", 1), 1);
	if (check_map_items(data))
		return (ft_putstr_fd("Error\nitems unknown", 1), 1);
	if ((is_game_object(data, 'P')) != 1)
		return (ft_putstr_fd("Error\nPlayer", 1), 1);
	if ((is_game_object(data, 'E')) != 1)
		return (ft_putstr_fd("Error\nExit", 1), 1);
	if (!is_game_object(data, 'C'))
		return (ft_putstr_fd("Error\nCollectables", 1), 1);

	return (0);
}

void	printmap(t_data *data)
{
	int	x;

	x = 0;
	while (data->map[x] != NULL)
	{
		ft_printf("\n%s", data->map[x]);
		x++;
	}
}

int	check_mapfile(t_data *data, int nb_args, char *file, char *tmp)
{
	int		error;
	char	**map;
	
	map = NULL;
	error = 0;
	if (nb_args == 2)
	{
		data->map = get_map(file, 0, tmp, map);
		free(map);
		if (!data->map)
		{
			return (0);
		}
		if (data->map[0] == NULL)
		{
			return (ft_putstr_fd("Error\nmap empty", 1), 0);
		}
		error = mapcheck(data);
		if (error)
			return (0);
	}
	return (1);
}