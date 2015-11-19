/*
** my_strncpy.c for my_strncpy in ~/dev/piscine/PJ6
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct  5 10:03:25 2015 marc brout
** Last update Sat Oct 17 10:35:27 2015 marc brout
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while ((src[i]) && (i < n))
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (n > my_strlen(src))
    dest[i] = 0;
  return (dest);
}
