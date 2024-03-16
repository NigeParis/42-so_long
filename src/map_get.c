/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:09:55 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/16 14:56:13 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_tab_chars(char str[])
{
	if (str)
		free(str);
}

void	ft_read_all_file(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
}

int	checkfile_exits(char *file, char *type_image)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!fd || fd == -1)
	{
		ft_printf("Error\n%s missing %s\n", type_image, file);
		close(fd);
		return (1);
	}
	close (fd);
	return (0);
}

char	*get_map_one_line(char *line, int fd, char *tmp)
{
	char	*tab;

	tab = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			ft_free_tab_chars(tmp);
			ft_free_tab_chars(line);
			ft_read_all_file(fd);
			close(fd);
			return (NULL);
		}
		tmp = ft_strjoin(tab, line);
		tab = tmp;
		ft_free_tab_chars(line);
		line = get_next_line(fd);
	}

	return (tab);
}









char	**get_map(char *file, int fd, char *tmp, char **map)
{
	char	*line;
	char	*tab;

	tab = NULL;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (!fd || fd == -1)
		return (ft_putstr_fd("Error\nfile.ber\n", 1), NULL);

	tab = get_map_one_line(line, fd, tmp);
	if (!tab)
		return (NULL);
	close(fd);
	if (line && ft_strlen(line) <= 1)
		return (free(line), NULL);
	map = ft_split(tab, '\n');
	ft_free_tab_chars(line);
	ft_free_tab_chars(tab);
	return (map);
}

