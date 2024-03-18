/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:39:49 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/18 18:53:35 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



void    flood_fill(char **tab, t_point *size, t_point *begin)
{

    char c;
    t_point p;
 
    c = tab[begin->y][begin->x];
   // ft_putchar_fd(c, 1);
 
    if (is_items_known(c, "0C"))
        tab[begin->y][begin->x] = ' ';
 
        
   
    if ((begin->x < (size->x - 1)) && (is_items_known((tab[begin->y][begin->x + 1]), " ")))
    {
        p.x = begin->x + 1;
        p.y = begin->y;

        flood_fill(tab, size, &p);
    }
    if ((begin->x > 0) && (is_items_known((tab[begin->y][begin->x - 1]), " ")))
    {
        p.x = begin->x - 1;
        p.y = begin->y;

        flood_fill(tab, size, &p);
    }
    if ((begin->y > 0) && (is_items_known((tab[begin->y - 1][begin->x]), " ")))
    {
        p.x = begin->x;
        p.y = begin->y - 1; 

        flood_fill(tab, size, &p);
    }
    if ((begin->y < (size->y - 1)) && (is_items_known((tab[begin->y + 1][begin->x]), " ")))
    {
        p.x = begin->x;
        p.y = begin->y + 1;

    }
    
}