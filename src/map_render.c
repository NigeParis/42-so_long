/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:35:11 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/13 11:00:21 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_tiles(t_data *data)
{
	int	posx;
	int	posy;

	posx = 0;
	posy = 0;
	data->bak_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/tile.xpm", &posx, &posy);
	data->playerup_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/up.xpm", &posx, &posy);
	data->playerdown_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/down.xpm", &posx, &posy);
	data->playerleft_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/left.xpm", &posx, &posy);
	data->playerright_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/right.xpm", &posx, &posy);
	data->wall_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/wall.xpm", &posx, &posy);
	data->coll_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/coll.xpm", &posx, &posy);
	data->exit_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/exit.xpm", &posx, &posy);
}

void	game_setup(t_data *data)
{
	data->player_pos_x = 0;
	data->player_pos_y = 0;
	data->move_x_left = JUMPLEFT;
	data->move_x_right = JUMPRIGHT;
	data->move_y_up = JUMPUP;
	data->move_y_down = JUMPDOWN;
	get_player_start(data);
	load_tiles(data);
}

void	get_player_start(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[x] != NULL)
	{
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'P')
			{
				data->player_pos_y = x * JUMPDOWN;
				data->player_pos_x = y * JUMPRIGHT;
				break ;
			}
			y++;
		}
		y = 0;
		x++;
	}
}

int	put_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while (y < data->window_size_y)
	{
		while (x < data->window_size_x)
		{
			if (data->map[(y / 100)][(x / 100)] == '0')				
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->bak_ptr, x, y);
			if (data->map[(y / 100)][(x / 100)] == '1')				
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->wall_ptr, x, y);
			if (data->map[(y / 100)][(x / 100)] == 'C')				
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->coll_ptr, x, y);
			if (data->map[(y / 100)][(x / 100)] == 'E')				
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->exit_ptr, x, y);
			x += 100;
		}
		if (x == data->window_size_x)
			x = 0;
		y += 100;	
	}
	return (1);
}
