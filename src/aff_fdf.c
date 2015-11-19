/*
** aff_fdf.c for fdf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Nov 19 09:49:45 2015 marc brout
** Last update Thu Nov 19 19:12:16 2015 marc brout
*/

#include "../include/fdf.h"

int			map_trax(t_fdftab *fdf,
				 t_bunny_position *tab,
				 t_bunny_pixelarray *pix,
				 t_color *color)
{
  t_bunny_position	*pos;
  int			i;
  int			j;
  int			k;

  k = 0;
  i = 0;
  if ((pos = bunny_malloc(sizeof(t_bunny_position) * 2)) == NULL)
    return (1);
  while (i < (fdf->h))
    {
      j = 0;
      while (j < (fdf->w - 1) && k < (fdf->h * fdf->w - 1))
	{
	  pos[0].x = tab[k].x;
	  pos[1].x = tab[k + 1].x;
	  pos[0].y = tab[k].y;
	  pos[1].y = tab[k + 1].y;
      	  /* my_printf("k = %d\norig x: %d, y: %d\n",k,pos[0].x,pos[0].y); */
	  /* my_printf("dest x: %d, y: %d\n\n",pos[1].x,pos[1].y); */
	  tekline(pix, pos, color);
	  k += 1;
	  j += 1;
	}
      k += 1;
      i += 1;
    }
  return (0);
}
int			map_tray(t_fdftab *fdf,
				 t_bunny_position *tab,
				 t_bunny_pixelarray *pix,
				 t_color *color)
{
  t_bunny_position	*pos;
  int			i;
  int			j;
  int			k;

  k = 0;
  i = 0;
  if ((pos = bunny_malloc(sizeof(t_bunny_position) * 2)) == NULL)
    return (1);
  while (i < (fdf->h))
    {
      j = 0;
      while (j <= (fdf->w) && k < (fdf->h * fdf->w - fdf->w))
	{
	  pos[0].x = tab[k].x;
	  pos[1].x = tab[k + fdf->w].x;
	  pos[0].y = tab[k].y;
	  pos[1].y = tab[k + fdf->w].y;
      	  /* my_printf("k = %d\norig x: %d, y: %d\n",k,pos[0].x,pos[0].y); */
	  /* my_printf("dest x: %d, y: %d\n\n",pos[1].x,pos[1].y); */
	  tekline(pix, pos, color);
	  k += 1;
	  j += 1;
	}

      i += 1;
    }
  return (0);
}

void		map_calc(t_fdftab *fdf)
{
  int		i;
  int		j;
  int		k;
  int		pas;
  int		basey;
  int		basex;

  i = 0;
  k = 0;
  pas = 90;
  basey = 200;
  basex = 500;
  while (i < fdf->h)
    {
      j = 0;
      while (j < fdf->w)
	{
	  fdf->tab[k].x += pas * j + basex;
	  fdf->tab[k].y = (fdf->tab[k].y * pas / 3) + basey;
	  j += 1;
	  k += 1;
	}
      basex -= pas;
      basey += pas;
      i += 1;
    }
}

void		my_fdf_square(t_bunny_pixelarray *pix,
			      t_bunny_position *pos,
			      t_bunny_position *squ,
			      t_color *color)
{
  int		l;
  int		h;
  
  l = pos->x;
  h = pos->y;
  while (pos->y < (h + squ->y))
    {
      pos->x = l;
      while (pos->x < (l + squ->x))
	{
	  tekpixel(pix, pos, color);
	  pos->x += 1;
	}
      pos->y += 1;
    }
}

int			my_fdf_aff(t_fdftab *fdf)
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	squ;
  t_bunny_position	pos;
  t_color		*color;

  color = bunny_malloc(sizeof(unsigned int *) * 2);
  color[0].full = BLACK;
  color[1].full = BLACK;
  squ.x = 1000;
  squ.y = 1000;
  pos.x = 0;
  pos.y = 0;
  pix = bunny_new_pixelarray(1000, 1000);
  win = bunny_start(1000, 1000, 0, "fil de fer 1");
  my_fdf_square(pix, &pos, &squ, color);
  start_const(fdf, pix, color);
  bunny_blit(&win->buffer, &pix->clipable, NULL);
  bunny_display(win);
  bunny_loop(win, 25, win);
  return (0);
}
