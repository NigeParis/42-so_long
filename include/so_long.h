/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:25:19 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/19 12:45:21 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <fcntl.h>
# define JUMPLEFT -100
# define JUMPRIGHT 100
# define JUMPUP -100
# define JUMPDOWN 100

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*bak_ptr;
	void	*playerup_ptr;
	void	*playerdown_ptr;
	void	*playerleft_ptr;
	void	*playerright_ptr;
	void	*wall_ptr;
	void	*coll_ptr;
	void	*exit_ptr;
	void	*noexit_ptr;
	int		player_pos_x;
	int		player_pos_y;
	int		window_size_x;
	int		window_size_y;
	int		exit;
	int		screen_width;
	int		screen_height;
	int		nbr_steps;
	char	**map;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		on_destroy(t_data *data);
int		put_map_background(t_data *data, int x, int y);
int		ft_ismap_rectangle(t_data *data);
int		ft_firstlastline_check(t_data *data, int line, int i);
int		ft_ismap_border(t_data *data);
int		keymove(int keysym, t_data *data, char key, char dir);
int		on_keypress(int keysym, t_data *data);
int		is_game_object(t_data *data, char c);
int		mapcheck(t_data *data);
int		is_items_known(char c, char *str);
int		check_map_items(t_data *data);
int		check_mapfile(t_data *data, int nb_args, char *file, char *tmp);
int		checkmap_size(t_data *data);
int		checkfile_exits(char *file, char *type_image);
int		list_file_errors(void);
void	get_map_size(t_data *data);
void	get_player_map_start_pos(t_data *data);
void	printmap(char **map);
void	player_move_north(t_data *data);
void	player_move_south(t_data *data);
void	player_move_east(t_data *data);
void	game_setup(t_data *data);
void	player_move_west(t_data *data);
void	clean_player_tracks(t_data *data);
void	open_exit(t_data *data);
void	exit_check_north(t_data *data, int pos_x, int pos_y);
void	exit_check_east(t_data *data, int pos_x, int pos_y);
void	exit_check_south(t_data *data, int pos_x, int pos_y);
void	exit_check_west(t_data *data, int pos_x, int pos_y);
void	load_tiles(t_data *data);
void	ft_free_tab_chars(char str[]);
void	ft_read_all_file(int fd);
char	**get_map(char *file, int fd, char *tmp, char **map);
char	*get_map_one_line(char *line, int fd, char *tmp);
char	**ft_mapdup(t_data *data);
void	flood_fill(char **tab, t_point *begin);
void	get_map_start_pos(char	**map, t_point *begin);
void	get_mapcopy_size(char	**map, t_point *size);
int		check_file_ext(char	*file,	char *ext);
int		pathcheck(t_data *data);
int		is_map_path(char **mapcopy);
int		is_uppercase_in_map(char **mapcopy);
#endif