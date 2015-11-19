/*
** my_swap.c for my_swap in /home/brout_m/dev/PJ4
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Oct  1 10:46:04 2015 marc brout
** Last update Sat Oct 17 13:01:31 2015 marc brout
*/

int	my_swap(int *a, int *b)
{
  int	stock;

  stock = *a;
  *a = *b;
  *b = stock;
  return (0);
}
