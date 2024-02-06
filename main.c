/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/02/06 17:12:26 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define KEYLEFT 65361
 
typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	void *bak_ptr;
	int player_pos_x;
	int player_pos_y;
	int move_x_left;
	int move_x_right;
	int move_y_up;
	int move_y_down;
} t_data;
 
int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	put_background(t_data *data)
{

mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->bak_ptr, data->player_pos_x, data->player_pos_y);

	return (1);
}

int	keymove(int keysym, t_data *data, char key, char dir)
{
	printf("Pressed key: %d : %u \n", key, keysym);
	put_background(data);

	if (keysym == key)
	{
		if (dir == 'E')
			data->player_pos_x += data->move_x_left;
		else if (dir == 'W')
			data->player_pos_x += data->move_x_right;
		else if (dir == 'N')
			data->player_pos_y += data->move_y_up;
		else if (dir == 'S')
			data->player_pos_y += data->move_y_down;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img_ptr, data->player_pos_x, data->player_pos_y);
	return (0);
}	



 
 int on_keypress(int keysym, t_data *data)
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
 
int main(void)
{
	int hi = 0;
	int wid = 0;

	
	t_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "So long :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	data.player_pos_x = 0;
	data.player_pos_y = 0;
	data.move_x_left = -100;
	data.move_x_right = 100;	
	data.move_y_up = -100;
	data.move_y_down = 100;	
	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr,
			"./assets/test.xpm", &hi, &wid);
	data.bak_ptr = mlx_xpm_file_to_image(data.mlx_ptr,
			"./assets/fond.xpm", &hi, &wid);





 	


	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	
	return (0);
}