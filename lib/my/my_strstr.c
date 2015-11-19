/*
** my_strstr.c for my_strstr in /home/brout_m/dev/piscine/PJ6
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct  5 14:42:02 2015 marc brout
** Last update Sun Oct 18 13:19:38 2015 marc brout
*/

char	*my_strstr(char *str, char *find)
{
  char	*deb;
  int	i;
  int	j;

  deb = str;
  i = 0;
  j = 0;
  while (str[i] && find[j])
    {
      j = 0;
      if (str[i] == find[j])
	{
	  while (str[i] == find[j] && find[j] && str[i])
	    {
	      i = i + 1;
	      j = j + 1;
	    }
	  if (find[j] == 0)
	    return (&deb[i - j]);
	}
      i = i + 1;
    }
  return (0);
}
