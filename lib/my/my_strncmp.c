/*
** my_strncmp.c for my_strncmp in /home/brout_m/dev/piscine/PJ6
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct  5 14:42:02 2015 marc brout
** Last update Sat Oct 17 10:34:53 2015 marc brout
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	total;
  int	i;

  i = 0;
  while ((s2[i]) && (s1[i]) && (s2[i] == s1[i]) && (i < n))
    i = i + 1;
  total = s1[i] - s2[i];
  return (total);
}

