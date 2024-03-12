/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/12 19:07:34 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	keymove(int keysym, t_data *data, char key, char dir)
{

	if (keysym == key)
	{
		if (dir == 'W' && data->player_pos_x > 0)
		{
			
			
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->bak_ptr, data->player_pos_x, data->player_pos_y);
			data->player_pos_x += data->move_x_left;	
			put_background(data);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->playerleft_ptr, data->player_pos_x, data->player_pos_y);
		}
		else if (dir == 'E' && data->player_pos_x < (data->window_size_x - JUMPRIGHT))
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->bak_ptr, data->player_pos_x, data->player_pos_y);
			data->player_pos_x += data->move_x_right;
			put_background(data);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->playerright_ptr, data->player_pos_x, data->player_pos_y);
		}
		else if (dir == 'N' && data->player_pos_y > 0)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->bak_ptr, data->player_pos_x, data->player_pos_y);
			data->player_pos_y += data->move_y_up;
			put_background(data);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->playerup_ptr, data->player_pos_x, data->player_pos_y);
		}
		else if (dir == 'S' && data->player_pos_y < (data->window_size_y - JUMPDOWN))
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->bak_ptr, data->player_pos_x, data->player_pos_y);
			data->player_pos_y += data->move_y_down;
			put_background(data);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->playerdown_ptr, data->player_pos_x, data->player_pos_y);
		}
	}
	printf("\nPressed key: %d -  player x : %d  player y : %d \n", key, data->player_pos_x, data->player_pos_y);
	

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
	
	return (0);
}
 