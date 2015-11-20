/*
** fdf_loop.c for fdf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Nov 20 04:17:45 2015 marc brout
** Last update Fri Nov 20 16:03:53 2015 marc brout
*/

#include "../include/fdf.h"

t_bunny_response       my_key(t_bunny_event_state state,
			      t_bunny_keysym keysym,
			      void *data)
{
  (void)data;
  if (keysym == BKS_ESCAPE)
    if (state == GO_DOWN)
      return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
