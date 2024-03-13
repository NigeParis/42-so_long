/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:53:12 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/13 18:18:30 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"





void	player_move_north(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_y = (data->player_pos_y / 100);
	pos_x = (data->player_pos_x / 100) - 1;
	if (data->map[pos_x][pos_y] != '1')
	{
		exit_check_north(data, pos_x, pos_y);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->playerup_ptr, data->player_pos_y, data->player_pos_x);
}



void	player_move_south(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_y = (data->player_pos_y / 100);
	pos_x = (data->player_pos_x / 100) + 1;
	if (data->map[pos_x][pos_y] != '1')
	{
		exit_check_south(data, pos_x, pos_y);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->playerdown_ptr, data->player_pos_y, data->player_pos_x);
}

void	player_move_east(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_y = (data->player_pos_y / 100) + 1;
	pos_x = (data->player_pos_x / 100);
	data->map[data->player_pos_x / 100][data->player_pos_y / 100] = '0';
	open_exit(data);
	if (data->map[pos_x][pos_y] != '1')
	{
		exit_check_east(data, pos_x, pos_y);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->playerright_ptr, data->player_pos_y, data->player_pos_x);
}

void	player_move_west(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_y = (data->player_pos_y / 100) - 1;
	pos_x = (data->player_pos_x / 100);
	data->map[data->player_pos_x / 100][data->player_pos_y / 100] = '0';
	open_exit(data);
	if (data->map[pos_x][pos_y] != '1')
	{
		exit_check_west(data, pos_x, pos_y);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->playerleft_ptr, data->player_pos_y, data->player_pos_x);
}