/*
** fdf.c for fdf1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Nov 18 18:21:07 2015 marc brout
** Last update Sat Nov 21 21:21:28 2015 marc brout
*/

#include <stdlib.h>
#include "../include/fdf.h"

void	conf_pas(t_fdftab *fdf)
{
  fdf->conf->pasx = (HEIGHT / (fdf->w + 3)) - (HEIGHT / (fdf->w + 3) / 6);
  fdf->conf->pasy = fdf->conf->pasx / 3;
  fdf->conf->offsetx = WIDTH - (fdf->w  * (fdf->conf->pasx + 1));
  fdf->conf->offsety = fdf->conf->pasy * (fdf->h + 1);
}

t_bunny_position	*bunnny_load(char *str, t_fdftab *ft)
{
  t_bunny_position	*pos;
  t_bunny_ini		*ini;

  if ((ini = bunny_load_ini(str)) == NULL)
    return (NULL);
  ft->w = my_getnbr((char*)bunny_ini_get_field(ini, "forme1", "width", 0));
  ft->h = my_getnbr((char*)bunny_ini_get_field(ini, "forme1", "height", 0));
  ft->conf->max = 0;
  conf_pas(ft);
  if ((pos = map_tab_load(ft, ini)) == NULL)
    return (NULL);
  if ((ft->tabo = map_tab_loado(ft, ini)) == NULL)
    return (NULL);
  if ((ft->tabw = map_tab_loadw(ft)) == NULL)
    return (NULL);
  bunny_delete_ini(ini);
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
      if ((z * ft->conf->pasy) > ft->conf->max)
	ft->conf->max = z;
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
  t_conf		conf;

  ftab.conf = &conf;
  if (ac < 2)
    return (1);
  if ((ftab.tab = bunnny_load(av[1], &ftab)) == NULL)
    return (1);
  my_fdf_aff(&ftab);
  bunny_free(ftab.tab);
  bunny_free(ftab.tabo);
  return (0);
}
