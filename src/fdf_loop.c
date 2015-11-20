/*
** fdf_loop.c for fdf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Nov 20 04:17:45 2015 marc brout
** Last update Fri Nov 20 05:45:53 2015 marc brout
*/

#include "../include/fdf.h"

t_bunny_response       my_key(t_bunny_event_state state,
		       t_bunny_keysym keysym, 
		       t_fdftab *data)
{
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  data->w = data->w;
  return (GO_ON);
}

t_bunny_loop			mainloop(t_bunny_window *window,
				 t_fdftab *fdf,
				 t_bunny_pixelarray *pix)
{
  t_color		color[2];

  color[0].full = BLACK;
  my_fdf_back(pix, &color[0]);
  start_const(fdf, pix, &color[0]);
  bunny_blit(&window->buffer, &pix->clipable, NULL);
  bunny_display(window);
  return (0);  
}
