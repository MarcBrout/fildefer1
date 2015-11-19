/*
** set_fdf.c for fdf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Nov 19 18:30:52 2015 marc brout
** Last update Thu Nov 19 19:15:00 2015 marc brout
*/

#include "../include/fdf.h"

t_bunny_position	*map_tab_loado(t_fdftab *ft)
{
  int			i;
  int			w;
  int			h;
  t_bunny_position	*pos;
  
  i = 0;
  w = 0;
  h = 0;
  if ((pos = bunny_malloc(sizeof(t_bunny_position) *
			  (ft->h * ft->w))) == NULL)
    return (NULL);
  while (i < (ft->h * ft->w))
    {
      tekllproject(&pos[i], w, h, 0);
      w += ((w == (ft->w)) ? (ft->w - 1) * -1 : 1);
      h += ((w == (ft->w)) ? 1 : 0);
      i++;
    }
  return (pos);
}

void		fdf_color(unsigned int col1, unsigned int col2, t_color *col)
{
  col[0].full = col1;
  col[1].full = col2;
}

void		start_const(t_fdftab *fdf,
			    t_bunny_pixelarray *pix,
			    t_color *color)
{
  fdf->tabo = map_tab_loado(fdf);
  map_calc(fdf);
  fdf_color(RED, WHITE, color);
  map_tray(fdf, fdf->tabo, pix, color);
  map_trax(fdf, fdf->tabo, pix, color);
  fdf_color(WHITE, RED, color);
  map_tray(fdf, fdf->tab, pix, color);
  map_trax(fdf, fdf->tab, pix, color);
}
