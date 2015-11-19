/*
** my_isneg.c for my_isneg in /home/brout_m/dev/lib
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Oct  6 10:24:35 2015 marc brout
** Last update Fri Oct 16 22:59:54 2015 marc brout
*/

int	my_isneg(int n)
{
  if (n < 0)
    {
      my_putchar('N');
      return (-1);
    }
  my_putchar('P');
  return (0);
}
