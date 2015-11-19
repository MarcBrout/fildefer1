/*
** my_strlowcase.c for my_strlowcase in ~/dev/piscine/PJ6
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct  5 21:18:51 2015 marc brout
** Last update Sat Oct 17 13:09:38 2015 marc brout
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= 65) && (str[i] <= 90))
	str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
