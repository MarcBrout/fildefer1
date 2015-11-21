/*
** fdf_loop.c for fdf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Nov 20 04:17:45 2015 marc brout
** Last update Sat Nov 21 14:01:48 2015 marc brout
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
