#include <stdio.h>
#include <stdlib.h>
int main()
{
  int account_balance = 1100;
  int total_cost =0;

  int min_val=2386095;
  int max_val=4772075;
  
  total_cost = min_val*900;
  printf ("\nMinimal number of flags - Final balance would be: %d\n",account_balance-total_cost);
  total_cost = max_val*900;
  printf ("\nMaximal number of flags - Final balance would be: %d\n",account_balance-total_cost);
}
