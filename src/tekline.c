/*
** tekline.c for fdf1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Nov 17 16:29:29 2015 marc brout
** Last update Wed Nov 18 11:52:10 2015 marc brout
*/

void	posey(t_bunny_pixelarray *pix,
	t_bunny_position *pos,
	t_color *color, int dst)
{
  while (pos[0].y != dst)
    {
      pos[0].y += ((pos[0].y > dst) ? -1 : ((pos[0].y == dst) ? 0 : 1));
      tekpixel(pix, pos[0], color);
    }
}

void	tekline(t_bunny_pixelarray *pix,
			t_bunny_position *pos,
			t_color	*color)
{
  float	a;
  int	b;

  a = (float)(pos[1].y - pos[0].y) / (float)(pos[1].x - pos[0].x);
  b = pos[0].y - a * pos[0].x;
  if (pos[0].x != pos[1].x)
    while (pos[0].x != pos[1].x)
      {
	tekpixel(pix, pos[0], color);
	pos[0].x += ((pos[0].x > pos[1].x) ? -1 : 1);
	posey(pix, pos[0], color, (int)(a * pos[0].x + b));
      }
  else
    posey(pix, pos[0], color, pos[0].y);
}
