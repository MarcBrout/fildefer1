/*
** my_strcapitalize.c for my_strcapitalize in ~/dev/piscine/PJ6
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct  5 21:18:51 2015 marc brout
** Last update Sun Oct 18 13:01:24 2015 marc brout
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= 97) && (str[i] <= 122))
	{
	  if (str[i - 1] < 48)
	    str[i] = str[i] - 32;
	}
      i = i + 1;
    }
  return (str);
}
