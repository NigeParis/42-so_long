/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/13 15:34:51 by nrobinso         ###   ########.fr       */
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


char	**get_map(void)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*tab;
	char	**map;

	tab = ft_strdup("");
	fd = open("map/map1.ber", O_RDONLY);
	if (!fd)
		return (write(1, "error", 5), NULL);
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
	map = ft_split(tab, '\n');
	if (line)
		free(line);
	close(fd);
	return (free(tmp), map);
}

void	get_map_size(t_data *data)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = (ft_strlen(data->map[0])) * JUMPRIGHT;
	while (data->map[i] != NULL)
		i++;
	x = i * JUMPDOWN;

	data->window_size_x = x;
	data->window_size_y = y;
}


int	main(void)
{
	t_data	data;
	int		error;

	data.map = get_map();
	error = mapcheck(&data);
	if (!error)
	{
		get_map_size(&data);
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			return (1);
		data.win_ptr = mlx_new_window(data.mlx_ptr, data.window_size_y, data.window_size_x, "So long :)");
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
