/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/15 17:38:42 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_setup(t_data *data)
{
	data->player_pos_x = 0;
	data->player_pos_y = 0;
	data->nbr_steps = 0;
	data->exit = 0;
	get_player_map_start_pos(data);

}

int	on_destroy(t_data *data)
{
	if (data->bak_ptr)
		mlx_destroy_image(data->mlx_ptr, data->bak_ptr);
	if (data->playerup_ptr)
		mlx_destroy_image(data->mlx_ptr, data->playerup_ptr);
	if (data->playerdown_ptr)
		mlx_destroy_image(data->mlx_ptr, data->playerdown_ptr);
	if (data->playerleft_ptr)
		mlx_destroy_image(data->mlx_ptr, data->playerleft_ptr);
	if (data->playerright_ptr)
		mlx_destroy_image(data->mlx_ptr, data->playerright_ptr);
	if (data->wall_ptr)
		mlx_destroy_image(data->mlx_ptr, data->wall_ptr);
	if (data->coll_ptr)
		mlx_destroy_image(data->mlx_ptr, data->coll_ptr);
	if (data->exit_ptr)
		mlx_destroy_image(data->mlx_ptr, data->exit_ptr);
	if (data->noexit_ptr)
		mlx_destroy_image(data->mlx_ptr, data->noexit_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_free_double_tab(data->map);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*tmp;

	tmp = NULL;
	if (argc != 2)
		return (ft_putstr_fd("Error\narguments", 1), 0);
	if (!check_mapfile(&data, argc, argv[1], tmp))
	{
		ft_free_tab_chars(tmp);
		return (0);
	}
	ft_free_tab_chars(tmp);
	get_map_size(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = 0;
	load_tiles(&data);
	if (checkmap_size(&data))
		return (on_destroy(&data), 1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.window_size_y, \
		data.window_size_x, "So long :)");
	if (!data.win_ptr)
		return (on_destroy(&data), 1);
	game_setup(&data);
	put_map_background(&data, 0, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.playerup_ptr, data.player_pos_y, data.player_pos_x);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
