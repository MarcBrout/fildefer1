/*
** tekllproject.c for fdf1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Nov 18 12:55:58 2015 marc brout
** Last update Thu Nov 19 23:00:05 2015 marc brout
*/

#include "../include/lapin.h"

void	tekllproject(t_bunny_position *out, int x, int y, int z)
{
  out->x = x + y;
  out->y = (z + y) * (-1);
}
