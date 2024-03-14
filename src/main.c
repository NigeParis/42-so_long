/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/14 13:12:12 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_setup(t_data *data)
{
	data->player_pos_x = 0;
	data->player_pos_y = 0;
	data->exit = 0;
	get_player_map_start_pos(data);
	load_tiles(data);
	put_map_background(data, 0, 0);

}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}


char	**get_map(char *file)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*tab;

	tab = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (!fd || fd == -1)
		return (write(1, "Error file.ber", 14), NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (!line || line[0] == '\n')
			break ;
		tmp = ft_strjoin(tab, line);
		tab = tmp;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (line)
	{
		if (ft_strlen(line) <= 1)
			return (free(line), NULL);
		free(line);
	}
	return (ft_split(tab, '\n'));
}






int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 2 && check_mapfile(&data, argc, argv[1]))
	{
		get_map_size(&data);
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			return (1);
		data.win_ptr = mlx_new_window(data.mlx_ptr, data.window_size_y, \
			data.window_size_x, "So long :)");
		if (!data.win_ptr)
			return (free(data.mlx_ptr), 1);
		game_setup(&data);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.playerup_ptr, data.player_pos_y, data.player_pos_x);
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
		mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
			&on_destroy, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
