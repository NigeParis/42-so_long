/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:25:19 by nrobinso          #+#    #+#             */
/*   Updated: 2024/02/07 17:20:04 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "libft.h"
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
	int		player_pos_x;
	int		player_pos_y;
	int		move_x_left;
	int		move_x_right;
	int		move_y_up;
	int		move_y_down;
}	t_data;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int	on_destroy(t_data *data);
int	put_background(t_data *data);




int	keymove(int keysym, t_data *data, char key, char dir);
int	on_keypress(int keysym, t_data *data);

#endif