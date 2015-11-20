/*
** tekline.c for fdf1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Nov 17 16:29:29 2015 marc brout
** Last update Fri Nov 20 03:30:51 2015 marc brout
*/

#include "../include/fdf.h"

void	posey(t_bunny_pixelarray *pix,
	      t_bunny_position *pos,
	      t_color *color, int dst)
{
  while (pos->y != dst)
    {
      tekpixel(pix, &pos[0], &color[0]);
      pos->y += ((pos->y == dst) ? 0 : ((pos->y > dst) ? -1 : 1));
    }
}

void	tekline(t_bunny_pixelarray *pix,
		t_bunny_position *pos,
		t_color	*color)
{
  float	a;
  int	b;

  a = (float)(pos[1].y - pos[0].y) / (float)(pos[1].x - pos[0].x);
  b = pos[0].y - a * pos[0].x;
  while (pos[0].x != pos[1].x)
    {
      tekpixel(pix, &pos[0], &color[0]);
      pos[0].x += ((pos[0].x > pos[1].x) ? -1 : 1);
      posey(pix, &pos[0], color, (a * pos[0].x + b));
    }
  posey(pix, &pos[0], color, pos[1].y);
}
