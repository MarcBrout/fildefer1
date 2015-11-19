/*
** aff_fdf.c for fdf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Nov 19 09:49:45 2015 marc brout
** Last update Thu Nov 19 23:16:47 2015 marc brout
*/

#include "../include/fdf.h"

void			map_trax(t_fdftab *fdf,
				 t_bunny_position *tab,
				 t_bunny_pixelarray *pix,
				 t_color *color)
{
  t_bunny_position	pos[2];
  int			i;
  int			j;
  int			k;

  k = 0;
  i = 0;
  while (i++ < (fdf->h))
    {
      j = 0;
      while (j++ < (fdf->w - 1) && k < (fdf->h * fdf->w - 1))
	{
	  pos[0].x = tab[k].x;
	  pos[1].x = tab[k + 1].x;
	  pos[0].y = tab[k].y;
	  pos[1].y = tab[k + 1].y;
	  tekline(pix, &pos[0], color);
	  k += 1;
	}
      k += 1;
    }
}

void			map_tray(t_fdftab *fdf,
				 t_bunny_position *tab,
				 t_bunny_pixelarray *pix,
				 t_color *color)
{
  t_bunny_position	pos[2];
  int			i;
  int			j;
  int			k;

  k = 0;
  i = 0;
  while (i++ < (fdf->h))
    {
      j = 0;
      while (j++ <= (fdf->w) && k < (fdf->h * fdf->w - fdf->w))
	{
	  pos[0].x = tab[k].x;
	  pos[1].x = tab[k + fdf->w].x;
	  pos[0].y = tab[k].y;
	  pos[1].y = tab[k + fdf->w].y;
	  my_printf("ligne n°%d x: %d y: %d à x: %d y: %d\n",k,pos[0].x,pos[0].y,pos[1].x,pos[1].y);
	  tekline(pix, &pos[0], color);
	  my_printf("=====================================\n");
	  k += 1;
	}
    }
}

void		map_calc(t_fdftab *fdf, t_bunny_position *tab)
{
  int		i;
  int		j;
  int		k;
  int		basey;
  int		basex;

  i = 0;
  k = 0;
  basey = 200;
  basex = 500;
  while (i++ < fdf->h)
    {
      j = 0;
      while (j < fdf->w)
	{
	  tab[k].x += PAS * j++ + basex;
	  tab[k].y = (tab[k].y * PAS / 3) + basey;
	  k++;
	}
      basex -= PAS;
      basey += PAS;
    }
}

void			my_fdf_back(t_bunny_pixelarray *pix,
				    t_color *color)
{
  t_bunny_position	pos;

  pos.y = 0;
  while (pos.y < HEIGHT)
    {
      pos.x = 0;
      while (pos.x < WIDTH)
	{
	  tekpixel(pix, &pos, color);
	  pos.x += 1;
	}
      pos.y += 1;
    }
}

void			my_fdf_aff(t_fdftab *fdf)
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_color		color[2];

  color[0].full = BLACK;
  pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  win = bunny_start(WIDTH, HEIGHT, 0, "fil de fer 1");
  my_fdf_back(pix, &color[0]);
  start_const(fdf, pix, &color[0]);
  bunny_blit(&win->buffer, &pix->clipable, NULL);
  bunny_display(win);
  bunny_loop(win, 25, win);
}
