/*
** my_is_prime.c for my_is_prime in /home/brout_m/dev/PJ5
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Oct  2 13:51:44 2015 marc brout
** Last update Sat Oct 17 10:21:15 2015 marc brout
*/

int	my_is_prime(int nombre)
{
  int	prime;

  if ((nombre == 1) || (nombre == 0))
    return (0);
  prime = 2;
  while ((nombre % prime) != 0)
    prime = prime + 1;
  if ((prime == nombre) || (prime == (nombre * -1)))
    return (1);
  return (0);
}
