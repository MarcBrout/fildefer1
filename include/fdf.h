/*
** fdf.h
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Nov 18 19:01:04 2015 marc brout
** Last update Fri Nov 20 05:47:04 2015 marc brout
*/

#ifndef FDF_H_
# define FDF_H_

#include "my.h"
#include "lapin.h"

#define COLOR_BACK BLACK
#define COLOR_ONE WHITE
#define COLOR_TWO RED
#define WIDTH 1024
#define HEIGHT 768
#define PAS 90

typedef struct		s_fdftab
{
  t_bunny_position	*tab;
  t_bunny_position	*tabo;
  int			h;
  int			w;
}			t_fdftab;

void start_const(t_fdftab *,
		 t_bunny_pixelarray *,
		 t_color *);
void fdf_plan(t_fdftab *,
	      t_bunny_position *,
	      t_bunny_pixelarray *,
	      t_color *);
t_bunny_position *bunnny_load(char *, t_fdftab *);
t_bunny_position *map_tab_load(t_fdftab *, t_bunny_ini *);
t_bunny_position *map_tab_loado(t_fdftab *);
void tekllproject(t_bunny_position *, int, int , int);
void link_plan(t_fdftab *,
	       t_bunny_pixelarray *,
	       t_color *);
void map_trax(t_fdftab *,
	      t_bunny_position *,
	      t_bunny_pixelarray *,
	      t_color *);
void map_tray(t_fdftab *,
	      t_bunny_position *,
	      t_bunny_pixelarray *,
	      t_color *);
void map_calc(t_fdftab *, t_bunny_position *);
void my_fdf_aff(t_fdftab *);
void my_fdf_back(t_bunny_pixelarray *,
		 t_color *);
void tekline(t_bunny_pixelarray *,
	     t_bunny_position *,
	     t_color *);
void posey(t_bunny_pixelarray *,
	   t_bunny_position *,
	   t_color *, int);
void tekpixel(t_bunny_pixelarray *,
	      t_bunny_position *,
	      t_color *);
t_bunny_loop mainloop(t_bunny_window *,
		      t_fdftab *,
		      t_bunny_pixelarray *);
t_bunny_response my_key(t_bunny_event_state,
		   t_bunny_keysym,
		   t_fdftab *);
#endif
