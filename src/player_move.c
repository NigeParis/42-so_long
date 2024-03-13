/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:53:12 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/13 10:58:43 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_move_north(t_data *data)
{
	data->player_pos_y += data->move_y_up;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->playerup_ptr, data->player_pos_x, data->player_pos_y);
}

void	player_move_south(t_data *data)
{
	data->player_pos_y += data->move_y_down;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->playerdown_ptr, data->player_pos_x, data->player_pos_y);
}

void	player_move_east(t_data *data)
{
	data->player_pos_x += data->move_x_right;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->playerright_ptr, data->player_pos_x, data->player_pos_y);
}

void	player_move_west(t_data *data)
{
	data->player_pos_x += data->move_x_left;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->playerleft_ptr, data->player_pos_x, data->player_pos_y);
}
