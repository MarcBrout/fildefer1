/*
** my_str_isupper.c for my_str_isupper in ~/dev/piscine/PJ6
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct  5 22:08:22 2015 marc brout
** Last update Sat Oct 17 13:10:52 2015 marc brout
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < 65) || (str[i] > 90))
	return (0);
      i = i + 1;
    }
  return (1);
}
