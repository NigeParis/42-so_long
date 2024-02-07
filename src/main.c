/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/02/07 15:26:05 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	put_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while (y < 800)
	{
		while (x < 1200)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->bak_ptr, x, y);
			x += 100;
		}
		if (x == 1200)
			x = 0;
		y += 100;
	}
	return (1);
}

void	game_setup(t_data *data)
{
	int posx = 0;
	int	posy = 0;

	data->player_pos_x = 0;
	data->player_pos_y = 0;
	data->move_x_left = JUMPLEFT;
	data->move_x_right = JUMPRIGHT;
	data->move_y_up = JUMPUP;
	data->move_y_down = JUMPDOWN;
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

}




int	main(void)
{
	t_data	data;
	int		fd;	
	char	*ptr;

	fd = open("map/map1.ber", O_RDONLY);
	if (!fd)
		return (write(1, "error",5));
	ptr = get_next_line(fd);
	ptr = get_next_line(fd);
	printf("\nOutput %s",ptr);
	free(ptr);
	close(fd);



	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1200, 800, "So long :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	game_setup(&data);

	put_background(&data);


	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.playerdown_ptr, 0, 0);




	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);

	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, &data);
	mlx_loop(data.mlx_ptr);






	return (0);
}