/*
** set_fdf.c for fdf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Nov 19 18:30:52 2015 marc brout
** Last update Sat Nov 21 19:58:37 2015 marc brout
*/

#include "../include/fdf.h"

void			link_plan(t_fdftab *fdf,
				  t_bunny_position *tab,
				  t_bunny_position *tabo,
				  t_color *color)
{
  t_bunny_position	pos[2];
  int			i;

  i = 0;
  while (i < fdf->h * fdf->w)
    {
      pos[0].x = tab[i].x;
      pos[0].y = tab[i].y - 1;
      pos[1].x = tabo[i].x;
      pos[1].y = tabo[i].y - 1;
      tekline(fdf->pix, &pos[0], color);
      i++;
    }
}

t_bunny_position	*map_tab_loadw(t_fdftab *ft)
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
      tekllproject(&pos[i], w, h, WATER_LVL);
      w += ((w == (ft->w)) ? (ft->w - 1) * -1 : 1);
      h += ((w == (ft->w)) ? 1 : 0);
      i++;
    }
  return (pos);
}

t_bunny_position	*map_tab_loado(t_fdftab *ft, t_bunny_ini *ini)
{
  int			i;
  int			w;
  int			h;
  int			z;
  t_bunny_position	*pos;

  i = 0;
  w = 0;
  h = 0;
  if ((pos = bunny_malloc(sizeof(t_bunny_position) *
			  (ft->h * ft->w))) == NULL)
    return (NULL);
  while (i < (ft->h * ft->w))
    {
      z = my_getnbr((char*)bunny_ini_get_field(ini, "forme1", "data", i));
      z = (z > 0) ? 0 : z;
      tekllproject(&pos[i], w, h, z);
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
  map_trax(fdf, tab, pix, color);
  map_tray(fdf, tab, pix, color);
}

void		start_const(t_fdftab *fdf,
			    t_bunny_pixelarray *pix,
			    t_color *color)
{
  color[0].full = COLOR_WATER;
  link_plan(fdf, fdf->tab, fdf->tabw, color);
  color[0].full = COLOR_WATER;
  fdf_plan(fdf, fdf->tabw, pix, color);
  color[0].full = COLOR_WATER;
  fdf_plan(fdf, fdf->tabw, pix, color);
  color[0].full = COLOR_TWO;
  fdf_plan(fdf, fdf->tabo, pix, color);
  link_plan(fdf, fdf->tab, fdf->tabo, color);
  color[0].full = COLOR_ONE;
  fdf_plan(fdf, fdf->tab, pix, color);
}
