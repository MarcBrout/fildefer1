/*
** my_find_prime_sup.c for my_find_prime_sup in ~/dev/PJ5
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Oct  2 14:14:58 2015 marc brout
** Last update Sat Oct 17 21:04:48 2015 marc brout
*/

int	my_find_prime_sup(int nb)
{
  int	isprime;

  isprime = my_is_prime(nb);
  if (isprime == 1)
    return (nb);
  nb = nb + 1;
  my_find_prime_sup(nb);
}
