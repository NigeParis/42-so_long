/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:17:44 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/14 13:08:08 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_exit(t_data *data)
{
	if ((!is_game_object(data, 'C')) && (data->exit == 0))
	{
		data->exit = 1;
		put_map_background(data, 0, 0);
	}	
}

void	exit_check_north(t_data *data, int pos_x, int pos_y)
{

	data->player_pos_x += JUMPUP;
	if (data->map[pos_x][pos_y] == 'E')
	{
		if (is_game_object(data, 'C') == 0)
		{
			ft_putstr_fd("Bravo - you have won !", 1);
			on_destroy(data);
		}
		else
			data->player_pos_x += JUMPDOWN;
	}
	if (data->map[pos_x][pos_y] == 'C')
		data->map[pos_x][pos_y] = '0';
	open_exit(data);

}

void	exit_check_south(t_data *data, int pos_x, int pos_y)
{

	data->player_pos_x += JUMPDOWN;
	if (data->map[pos_x][pos_y] == 'E')
	{
		if (is_game_object(data, 'C') == 0)
		{
			ft_putstr_fd("Bravo - you have won !", 1);
			on_destroy(data);
		}
		else
			data->player_pos_x += JUMPUP;
	}
	if (data->map[pos_x][pos_y] == 'C')
		data->map[pos_x][pos_y] = '0';
	open_exit(data);

}

void	exit_check_east(t_data *data, int pos_x, int pos_y)
{

	data->player_pos_y += JUMPRIGHT;
	if (data->map[pos_x][pos_y] == 'E')
	{
		if (is_game_object(data, 'C') == 0)
		{
			ft_putstr_fd("Bravo - you have won !", 1);
			on_destroy(data);
		}
		else
			data->player_pos_y += JUMPLEFT;
	}
	if (data->map[pos_x][pos_y] == 'C')
		data->map[pos_x][pos_y] = '0';
	open_exit(data);

}

void	exit_check_west(t_data *data, int pos_x, int pos_y)
{

	data->player_pos_y += JUMPLEFT;
	if (data->map[pos_x][pos_y] == 'E')
	{
		if (is_game_object(data, 'C') == 0)
		{
			ft_putstr_fd("Bravo - you have won !", 1);
			on_destroy(data);
		}
		else
			data->player_pos_y += JUMPRIGHT;
	}
	if (data->map[pos_x][pos_y] == 'C')
		data->map[pos_x][pos_y] = '0';
	open_exit(data);

}
