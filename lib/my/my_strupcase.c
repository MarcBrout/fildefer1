/*
** my_strupcase.c for my_strupcase in /home/brout_m/dev/piscine/PJ6
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct  5 21:18:51 2015 marc brout
** Last update Sat Oct 17 10:36:27 2015 marc brout
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= 97) && (str[i] <= 122))
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
