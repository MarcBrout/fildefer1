/*
** my_str_islower.c for my_str_islower in /home/brout_m/dev/piscine/PJ6
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct  5 22:08:22 2015 marc brout
** Last update Sat Oct 17 10:29:47 2015 marc brout
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < 97) || (str[i] > 122))
	return (0);
      i = i + 1;
    }
  return (1);
}
