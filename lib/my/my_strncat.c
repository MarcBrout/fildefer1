/*
** my_strncat.c for my_strncat in /home/brout_m/dev/lib
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Oct  6 13:37:20 2015 marc brout
** Last update Thu Oct 15 19:53:04 2015 marc brout
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  i = my_strlen(dest);
  j = 0;
  while ((src[j] >= 0) && (j < nb))
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}
