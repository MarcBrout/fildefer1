/*
** set_fdf.c for fdf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Nov 19 18:30:52 2015 marc brout
** Last update Thu Nov 19 22:27:12 2015 marc brout
*/

#include "../include/fdf.h"

void			link_plan(t_fdftab *fdf,
				  t_bunny_pixelarray *pix,
				  t_color *color)
{
  t_bunny_position	pos[2];
  int			i;

  i = 0;
  while (i < fdf->h *fdf->w)
    {
      pos[0].x = fdf->tab[i].x;
      pos[0].y = fdf->tab[i].y;
      pos[1].x = fdf->tabo[i].x;
      pos[1].y = fdf->tabo[i].y;
      tekline(pix, &pos[0], color);
      i++;
    }
}

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

void		fdf_plan(t_fdftab *fdf,
			 t_bunny_position *tab,
			 t_bunny_pixelarray *pix,
			 t_color *color)
{
  map_calc(fdf, tab);
  map_tray(fdf, tab, pix, color);
  map_trax(fdf, tab, pix, color);  
}

void		start_const(t_fdftab *fdf,
			    t_bunny_pixelarray *pix,
			    t_color *color)
{
  color[0].full = COLOR_TWO;
  fdf_plan(fdf, fdf->tabo, pix, color);
  color[0].full = COLOR_ONE;
  fdf_plan(fdf, fdf->tab, pix, color);
  color[0].argb[ALPHA_CMP] = 125;
  link_plan(fdf, pix, color);
}
