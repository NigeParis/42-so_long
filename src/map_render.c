/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:35:11 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/13 17:30:46 by nrobinso         ###   ########.fr       */
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
	data->noexit_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/noexit.xpm", &posx, &posy);
}

void	game_setup(t_data *data)
{
	data->player_pos_x = 0;
	data->player_pos_y = 0;
	data->exit = 0;
	get_player_start(data);
	load_tiles(data);
	put_background(data, 0, 0);

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
				data->player_pos_y = y * JUMPRIGHT;
				data->player_pos_x = x * JUMPDOWN;
				data->map[x][y] = '0';
				break ;
			}
			y++;
		}
		y = 0;
		x++;
	}
}

int	put_background(t_data *data, int x, int y)
{
	while (x < data->window_size_x)
	{
		y = 0;
		while (y < data->window_size_y)
		{
			if (data->map[(x / 100)][(y / 100)] == '0')				
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->bak_ptr, y, x);
			if (data->map[(x / 100)][(y / 100)] == '1')				
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->wall_ptr, y, x);
			if (data->map[(x / 100)][(y / 100)] == 'C')				
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->coll_ptr, y, x);
			if (data->map[(x / 100)][(y / 100)] == 'E')				
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->noexit_ptr, y, x);
			y += JUMPRIGHT;
		}
		x += JUMPDOWN;
	}
	return (1);
}
