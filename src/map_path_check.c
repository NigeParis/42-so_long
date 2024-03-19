/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:39:49 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/19 12:27:46 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_map_path(char **mapcopy)
{
	t_point	size;
	t_point	begin;
	t_point	*ptr_begin;
	t_point	*ptr_size;

	ptr_begin = &begin;
	ptr_size = &size;
	get_map_start_pos(mapcopy, ptr_begin);
	get_mapcopy_size(mapcopy, ptr_size);
	flood_fill(mapcopy, &begin);
	flood_fill(mapcopy, &begin);
	if (is_uppercase_in_map(mapcopy))
	{
		ft_free_double_tab(mapcopy);
		return (1);
	}
	ft_free_double_tab(mapcopy);
	return (0);
}

void	flood_fill(char **tab, t_point *begin)
{
	t_point	p;

	p.x = begin->x;
	p.y = begin->y;
	if (tab[p.y][p.x] == '1' || tab[p.y][p.x] == ' ')
		return ;
	if (tab[p.y][p.x] == 'E')
	{
		tab[p.y][p.x] = ' ';
		return ;
	}
	tab[p.y][p.x] = ' ';
	p.y = begin->y - 1;
	p.x = begin->x;
	flood_fill(tab, &p);
	p.y = begin->y;
	p.x = begin->x - 1;
	flood_fill(tab, &p);
	p.y = begin->y + 1;
	p.x = begin->x;
	flood_fill(tab, &p);
	p.y = begin->y;
	p.x = begin->x + 1;
	flood_fill(tab, &p);
}

void	get_mapcopy_size(char **map, t_point *size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		while (map[y][x])
		{
			x++;
		}
		size->x = x;
		x = 0;
		y++;
	}
	size->y = y;
}

int	pathcheck(t_data *data)
{
	char	**mapcopy;

	mapcopy = ft_mapdup(data);
	if (is_map_path(mapcopy))
		return (1);
	return (0);
}

void	printmap(char **map)
{
	int	x;

	x = 0;
	while (map && map[x] != NULL)
	{
		ft_printf("\n%s", map[x]);
		x++;
	}
}
