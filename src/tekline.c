/*
** tekline.c for fdf1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Nov 17 16:29:29 2015 marc brout
** Last update Thu Nov 19 23:33:55 2015 marc brout
*/

#include "../include/fdf.h"

void	posey(t_bunny_pixelarray *pix,
	      t_bunny_position *pos,
	      t_color *color, int dst)
{
  while (pos->y != dst)
    {
      my_printf("dst = %d\n", dst);
      my_printf("pixel x: %d Y: %d\n", pos[0].x, pos[0].y);
      pos->y += ((pos->y == dst) ? 0 : ((pos->y > dst) ? -1 : 1));      
      tekpixel(pix, &pos[0], &color[0]);
    }
}

void	tekline(t_bunny_pixelarray *pix,
		t_bunny_position *pos,
		t_color	*color)
{
  float	a;
  int	b;
  int	c;

  a = (float)(pos[1].y - pos[0].y) / (float)(pos[1].x - pos[0].x);
  b = pos[0].y - a * pos[0].x + 1;
  if (pos[0].x != pos[1].x)
    while (pos[0].x != pos[1].x)
      {
	my_printf("pixel X: %d y: %d\n", pos[0].x, pos[0].y);
	tekpixel(pix, &pos[0], &color[0]);
	c = (a * pos[0].x + b);
	pos[0].x += ((pos[0].x > pos[1].x) ? -1 : 1);
	posey(pix, &pos[0], color, c);
      }
  else
    posey(pix, &pos[0], color, pos[1].y);
  tekpixel(pix, &pos[1], &color[0]);
}
