/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:25:19 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/14 18:44:01 by nrobinso         ###   ########.fr       */
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
	char	**map;
}	t_data;



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
void	get_map_size(t_data *data);
void	get_player_map_start_pos(t_data * data);
void	printmap(t_data *data);
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
char	**get_map(char *file, int fd, char *tmp, char **map);

#endif