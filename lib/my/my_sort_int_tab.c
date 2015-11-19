/*
** my_sort_int_tab.c for my_sort_int_tab in /home/brout_m/dev/lib
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Oct  6 10:59:36 2015 marc brout
** Last update Tue Oct  6 11:43:37 2015 marc brout
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	j;
  int	stock;

  i = 0;
  while (i <= (size - 1))
    {
      j = i;
      while (j <= (size - 1))
	{
	  if (tab[i] > tab[j])
	    {
	      stock = tab[i];
	      tab[i] = tab[j];
	      tab[j] = stock;
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}
