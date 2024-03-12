/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:40:57 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/12 14:40:56 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_chars(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][y] != '\0')
		{
			if (!is_items_known(data->map[i][y], "PCE01"))
				return (1);
			y++;
		}
		y = 0;
		i++;
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
