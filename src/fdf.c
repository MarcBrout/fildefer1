/*
** fdf.c for fdf1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Nov 18 18:21:07 2015 marc brout
** Last update Fri Nov 20 15:28:30 2015 marc brout
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../include/fdf.h"

t_bunny_position	*bunnny_load(char *str, t_fdftab *ft)
{
  t_bunny_position	*pos;
  t_bunny_ini		*ini;

  ini = bunny_load_ini(str);
  ft->w = my_getnbr((char*)bunny_ini_get_field(ini, "forme1", "width", 0));
  ft->h = my_getnbr((char*)bunny_ini_get_field(ini, "forme1", "height", 0));
  if ((pos = map_tab_load(ft, ini)) == NULL)
    return (NULL);
  return (pos);
}

t_bunny_position	*map_tab_load(t_fdftab *ft, t_bunny_ini *ini)
{
  int			i;
  int			z;
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
      z = my_getnbr((char*)bunny_ini_get_field(ini, "forme1", "data", i));
      tekllproject(&pos[i], w, h, z);
      w += ((w == (ft->w)) ? (ft->w - 1) * -1 : 1);
      h += ((w == (ft->w)) ? 1 : 0);
      i++;
    }
  return (pos);
}

int			main(int ac, char **av)
{
  t_fdftab		ftab;

  if (ac < 2)
    return (1);
  if ((ftab.tab = bunnny_load(av[1], &ftab)) == NULL)
    return (1);
  if ((ftab.tabo = map_tab_loado(&ftab)) == NULL)
    return (1);
  my_fdf_aff(&ftab);
  if (ftab.tab != NULL && ftab.tabo != NULL)
    {
      bunny_free(ftab.tab);
      bunny_free(ftab.tabo);
    }
  return (0);
}
