/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/02/07 12:36:13 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	keymove(int keysym, t_data *data, char key, char dir)
{
	printf("Pressed key: %d : %u \n", key, keysym);

	if (keysym == key)
	{
		if (dir == 'E' && data->player_pos_x > 0)
		{
			data->player_pos_x += data->move_x_left;	
			put_background(data);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->playerleft_ptr, data->player_pos_x, data->player_pos_y);
		}
		else if (dir == 'W' && data->player_pos_x < 1100)
		{
			data->player_pos_x += data->move_x_right;
			put_background(data);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->playerright_ptr, data->player_pos_x, data->player_pos_y);
		}
		else if (dir == 'N' && data->player_pos_y > 0)
		{
			data->player_pos_y += data->move_y_up;
			put_background(data);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->playerup_ptr, data->player_pos_x, data->player_pos_y);
		}
		else if (dir == 'S' && data->player_pos_y < 700)
		{
			data->player_pos_y += data->move_y_down;
			put_background(data);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->playerdown_ptr, data->player_pos_x, data->player_pos_y);
		}
	}

	return (0);
}	


int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65361)
		keysym = 'a';
	if (keysym == 65363)
		keysym = 's';	
	if (keysym == 65362)
		keysym = 'w';	
	if (keysym == 65364)
		keysym = 'z';
	keymove(keysym, data, 'w', 'N');
	keymove(keysym, data, 'z', 'S');
	keymove(keysym, data, 'a', 'E');
	keymove(keysym, data, 's', 'W');
	return (0);
}
 