/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/15 15:59:24 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	clean_player_tracks(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->bak_ptr, data->player_pos_y, data->player_pos_x);
}


int	keymove(int keysym, t_data *data, char key, char dir)
{
	if (keysym == key)
	{
		printf("\nPressed key: %d -  player x : %d  player y : %d \n", key, data->player_pos_x /100, data->player_pos_y / 100);
		clean_player_tracks(data);
		if (dir == 'W' && data->player_pos_x > 0)
			player_move_west(data);
		else if (dir == 'E' && data->player_pos_x < (data->window_size_x - JUMPRIGHT))
			player_move_east(data);
		else if (dir == 'N' && data->player_pos_y > 0)
			player_move_north(data);
		else if (dir == 'S' && data->player_pos_y < (data->window_size_y - JUMPDOWN))
			player_move_south(data);
	}
	printmap(data);
	return (0);
}	


int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65363 || keysym == 's')
	{
		keysym = 's';
		keymove(keysym, data, 's', 'E');
	}
	if (keysym == 65361 || keysym == 'a')
	{
		keysym = 'a';	
		keymove(keysym, data, 'a', 'W');
	}	
	if (keysym == 65362 || keysym == 'w')
	{
		keysym = 'w';	
		keymove(keysym, data, 'w', 'N');
	}
	if (keysym == 65364 || keysym == 'z')
	{
		keysym = 'z';
		keymove(keysym, data, 'z', 'S');
	}
	if (keysym == 65307)
		on_destroy(data);	
	return (0);
}
 