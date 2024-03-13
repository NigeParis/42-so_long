/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:40:57 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/13 12:39:13 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_chars(t_data *data)
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
		return (ft_putstr_fd("Error not a Rectangle", 1), 1);
	if (ft_ismap_border(data))
		return (ft_putstr_fd("Error Border", 1), 1);
	if (check_map_chars(data))
		return (ft_putstr_fd("Error items unknown", 1), 1);
	if ((is_game_object(data, 'P')) != 1)
		return (ft_putstr_fd("Error Player", 1), 1);
	if ((is_game_object(data, 'E')) != 1)
		return (ft_putstr_fd("Error Exit", 1), 1);
	if (!is_game_object(data, 'C'))
		return (ft_putstr_fd("Error Collectables", 1), 1);
	return (0);
}

void	printmap(t_data *data)
{
	int	x;

	x = 0;
	while (data->map[x] != NULL)
	{
		printf("\n%s", data->map[x]);
		x++;
	}
}