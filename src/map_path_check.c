/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:39:49 by nrobinso          #+#    #+#             */
/*   Updated: 2024/01/04 13:08:24 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include "../include/so_long.h"



char   items_to_lowercase()
{

    return (' ');
}




void  flood_fill(char **tab, t_point *size, t_point *begin)
{

    char c;

    t_point p;
 


    c = tab[begin->y][begin->x];


    if ((c != '1'))
    {   
        tab[begin->y][begin->x] = items_to_lowercase();
        if (((tab[begin->y][begin->x]) != 'e'))
        {
            c = '0';
        }
        else
             tab[begin->y][begin->x] = items_to_lowercase();
            
    }
   // printf("\nc : %c  size_x : %d  size_y : %d  bigin_x : %d  begin_y :%d", c, size->x, size->x, begin->x, begin->y);

    if ((begin->y > 0 && tab[begin->y - 1][begin->x] == 'E'))
        tab[begin->y - 1][begin->x] = 'e';

    if ((begin->y < (size->y - 1)) && tab[begin->y + 1][begin->x] == 'E')
        tab[begin->y + 1][begin->x] = 'e';
 
    if ((begin->x < (size->x - 1)) && tab[begin->y][begin->x + 1] == 'E')
        tab[begin->y][begin->x + 1] = 'e';

    if (begin->x > 0 && tab[begin->y][begin->x - 1] == 'E')
        tab[begin->y][begin->x - 1] = 'e';

      
    
        

    


    if ((begin->y > 0 && tab[begin->y - 1][begin->x] == c) || 
        (begin->y > 0 && tab[begin->y - 1][begin->x] == 'P')||
        (begin->y > 0 && tab[begin->y - 1][begin->x] == 'C'))
    {
        p.x = begin->x;
        p.y = begin->y - 1;

 
  
        if ((tab[p.y][p.x] != '1') || (tab[p.y][p.x] != 'e'))
           tab[p.y][p.x] = items_to_lowercase();
        flood_fill(tab, size, &p);
    }



    if (((begin->y < (size->y - 1)) && tab[begin->y + 1][begin->x] == c) || 
        ((begin->y < (size->y - 1)) && tab[begin->y + 1][begin->x] == 'P')||
        ((begin->y < (size->y - 1)) && tab[begin->y + 1][begin->x] == 'C'))
    {
        p.x = begin->x;
        p.y = begin->y + 1;
    
  
    
      if ((tab[p.y][p.x] != '1') || (tab[p.y][p.x] != 'e'))
           tab[p.y][p.x] = items_to_lowercase();
        flood_fill(tab, size, &p);
    }

    if (((begin->x < (size->x - 1)) && tab[begin->y][begin->x + 1] == c) || 
        ((begin->x < (size->x - 1)) && tab[begin->y][begin->x + 1] == 'P')||
        ((begin->x < (size->x - 1)) && tab[begin->y][begin->x + 1] == 'C'))
    {
        p.x = begin->x + 1;
        p.y = begin->y;


    
        if ((tab[p.y][p.x] != '1') || (tab[p.y][p.x] != 'e'))
           tab[p.y][p.x] = items_to_lowercase();
        flood_fill(tab, size, &p);
    }
    if ((begin->x > 0 && tab[begin->y][begin->x - 1] == c) || 
        (begin->x > 0 && tab[begin->y][begin->x - 1] == 'P')||
        (begin->x > 0 && tab[begin->y][begin->x - 1] == 'C'))
    {
        p.x = begin->x - 1;
        p.y = begin->y;

    
    
       if ((tab[p.y][p.x] != '1') || (tab[p.y][p.x] != 'e'))
           tab[p.y][p.x] = items_to_lowercase();
        flood_fill(tab, size, &p);
    }
}


/*
char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{

	t_point size = {8, 5};

	char *zone[] = {
		"11111111",
		"1PCC0001",
		"10111111",
		"100000E1",
		"11111111",
	};

    int i;
	char**  area = make_area(zone, size);

	for (i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");
	t_point begin = {1, 1};

	flood_fill(area, size, begin);
	for (i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);

	return (0);
}
*/