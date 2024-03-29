/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:25:43 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/19 12:31:34 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_mapdup(t_data *data)
{
	char	**newmap;	
	int		row;
	int		i;

	row = 0;
	i = 0;
	newmap = NULL;
	if (!data->map)
		return (0);
	while (data->map && data->map[row])
		row++;
	newmap = (char **)malloc(sizeof(char *) * (row + 1));
	if (!newmap)
		return (0);
	while (data->map[i])
	{
		newmap[i] = ft_strdup(data->map[i]);
		i++;
	}
	newmap[i] = NULL;
	return (newmap);
}

void	get_map_start_pos(char **map, t_point *begin)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				begin->y = y;
				begin->x = x;
				map[y][x] = '0';
				break ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	check_file_ext(char *file,	char *ext)
{
	int	len;
	int	len_ext;
	int	i;

	i = 0;
	if (!file || !ext)
		return (1);
	if (file[0] == '\0' || ext[0] == '\0')
		return (1);
	len_ext = ft_strlen(ext) + 1;
	len = ft_strlen(file) + 1;
	while (file[((len - len_ext) + i)] != '\0')
	{
		if ((file[((len - len_ext) + i)]) != ext[i])
			return (1);
		i++;
	}
	return (0);
}
