/*
** fdf_loop.c for fdf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Nov 20 04:17:45 2015 marc brout
** Last update Sun Nov 22 18:45:52 2015 marc brout
*/

#include "../include/fdf.h"

t_bunny_response	my_key(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *data)
{
  if (keysym == BKS_ESCAPE)
    if (state == GO_DOWN)
      {
	(void)data;
	return (EXIT_ON_SUCCESS);
      }
  return (GO_ON);
}

t_bunny_response	main_loop(void *data)
{
  t_fdftab		*fdf;

  fdf = data;
  my_fdf_back(fdf->pix, fdf->back);
  start_const(fdf, fdf->pix, fdf->col);
  bunny_blit(&fdf->win->buffer, &fdf->pix->clipable, NULL);
  bunny_display(fdf->win);
  return (GO_ON);
}

int	check_ini(t_bunny_ini *ini)
{
  if (bunny_ini_get_field(ini, "forme1", "type", 0) == NULL)
    return (6);
  if (my_strcmp(bunny_ini_get_field(ini, "forme1", "type", 0),"fdf1"))
    return (4);
  if (bunny_ini_get_field(ini, "forme1", "width", 0) == NULL ||
      my_strcmp(bunny_ini_get_field(ini, "forme1", "width", 0), "0") == 0)
    return (1);
  if (bunny_ini_get_field(ini, "forme1", "height", 0) == NULL ||
      my_strcmp(bunny_ini_get_field(ini, "forme1", "height", 0), "0") == 0)
    return (2);
  return (0);
}

void	free_tab(t_fdftab *ftab)
{
  if (ftab->tab != NULL)
    bunny_free(ftab->tab);
  if (ftab->tab != NULL)
    bunny_free(ftab->tabo);
  if (ftab->tab != NULL)
    bunny_free(ftab->tabw);
}

void	my_alpha_to(t_color *col, t_color *col2, int pas)
{
  while (pas-- > 0)
    {
      col->argb[0] += ((col->argb[0] > col2->argb[0]) ? -1 :
		       (col->argb[0] == col2->argb[0]) ? 0 : -1);
      col->argb[1] += ((col->argb[1] > col2->argb[1]) ? -1 :
		       (col->argb[1] == col2->argb[1]) ? 0 : 1);
      col->argb[2] += ((col->argb[2] > col2->argb[2]) ? -1 :
		       (col->argb[2] == col2->argb[2]) ? 0 : 1);
    }
}
