/*
** my_str_isprintable.c for my_str_isprintable in ~/dev/piscine/PJ6
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct  5 22:08:22 2015 marc brout
** Last update Sat Oct 17 13:11:38 2015 marc brout
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 33)
	return (0);
      i = i + 1;
    }
  return (1);
}
