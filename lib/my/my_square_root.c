/*
** my_square_root.c for my_square_root in /home/brout_m/dev/PJ5
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Oct  2 13:22:46 2015 marc brout
** Last update Sat Oct 17 10:26:43 2015 marc brout
*/

int	my_square_root(int nb)
{
  int	square;

  if (nb < 0)
    return (0);
  square = 2;
  while ((square * square) < nb)
    square = square + 1;
  if ((square * square) == nb)
    return (square);
  return (0);
}
