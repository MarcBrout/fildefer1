/*
** tekpixel.c for fdf1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Nov 17 16:24:48 2015 marc brout
** Last update Thu Nov 19 13:57:00 2015 marc brout
*/

#include "../include/lapin.h"

void		tekpixel(t_bunny_pixelarray	*pix,
			 t_bunny_position	*pos,
			 t_color		*color)
{
  t_color	*col;
  
  col = (t_color*)pix->pixels + (pos->x +
				 (pos->y * pix->clipable.clip_width));
  col->full = color->full;
}
