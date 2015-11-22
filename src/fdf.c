/*
** fdf.c for fdf1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Nov 18 18:21:07 2015 marc brout
** Last update Sun Nov 22 06:43:07 2015 marc brout
*/

#include <stdlib.h>
#include "../include/fdf.h"

void	conf_pas(t_fdftab *fdf)
{
  int	small;

  small = (HEIGHT < WIDTH) ? HEIGHT : WIDTH;
  fdf->conf->pasx = ((small / fdf->w) * 3) / 5;
  fdf->conf->pasy = fdf->conf->pasx / 3;
  fdf->conf->offsetx = WIDTH - (fdf->w  * (fdf->conf->pasx + 1));
  fdf->conf->offsety = fdf->conf->pasy * (fdf->h + 1);
}

int			bunnny_load(char *str, t_fdftab *ft)
{
  int			i;

  if ((ft->ini = bunny_load_ini(str)) == NULL)
    return (5);
  if ((i = check_ini(ft->ini)) > 0)
    return (i);
  ft->w = my_getnbr((char*)bunny_ini_get_field(ft->ini,
					       "forme1", "width", 0));
  ft->h = my_getnbr((char*)bunny_ini_get_field(ft->ini,
					       "forme1", "height", 0));
  ft->conf->max = 0;
  conf_pas(ft);
  if (((ft->tab = map_tab_load(ft, ft->ini)) == NULL) ||
      ((ft->tabo = map_tab_loado(ft, ft->ini)) == NULL) ||
      ((ft->tabw = map_tab_loadw(ft)) == NULL))
    return (3);
  return (0);
}

t_bunny_position	*map_tab_load(t_fdftab *ft, t_bunny_ini *ini)
{
  int			i;
  int			z;
  char			*test;
  t_bunny_position	*pos;

  i = 0;
  if ((pos = bunny_malloc(sizeof(t_bunny_position) *
			  (ft->h * ft->w))) == NULL)
    return (NULL);
  while (i < (ft->h * ft->w))
    {
      if ((test = (char *)bunny_ini_get_field(ini, "forme1", "data", i))
	  == NULL)
	return (NULL);
      z = my_getnbr(test);
      if ((z * ft->conf->pasy) > ft->conf->max)
	ft->conf->max = z;
      tekllproject(&pos[i], i % ft->w, i / ft->w, z);
      i++;
    }
  return (pos);
}

int			main(int ac, char **av)
{
  t_fdftab		ftab;
  t_conf		conf;
  int			i;

  ftab.conf = &conf;
  if (ac < 2)
    return (1);
  if ((i = bunnny_load(av[1], &ftab)) > 0)
    return (aff_err(i));
  my_fdf_aff(&ftab);
  free_tab(&ftab);
  return (0);
}
