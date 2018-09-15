/*
ID: talos
LANG: C
PROG: milk
 */

#define INPUT "milk.in"     /* input file*/
#define OUTPUT "milk.out"   /* output file*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
  /* definitions */
  long int c1 , c2;
  unsigned long int  n, sum  , temp ;
  unsigned short int  key , m;
  FILE *in , *out;
  
  /* read n , m , data */
  in=fopen(INPUT, "r");
  fscanf (in, "%lu %hu\n", &n , &m);
  unsigned short int p[m];
  unsigned long int q[m];

  /* for each m read price and quantity*/
  for (c1=0; c1 < m; c1++)
  {
    fscanf (in, "%hu %lu\n", &p[c1] , &q[c1]);
  }
  fclose (in); 

  /* sort by price , insertion sort */
  for (c1 = 1; c1 < m; c1++)
  {
    key = p[c1];
    temp = q[c1];
    c2 = c1 - 1;
    while ((c2>-1) && (p[c2] > key))
    {
      p[c2 + 1] = p[c2];
      q[c2 + 1] = q[c2];
      c2--;
    }
    p[c2 + 1 ] = key;
    q[c2 + 1 ] = temp;
  }

  sum=0;
  c1=0;
  /* while total quantity < n*/
  while (n > 0)
  {
    /* get milk (quantity) and compute sum=p*q */
    if (n > q[c1])
    {
      sum+=p[c1] * q[c1];
      n-=q[c1];
    } else
    {
      sum+=n * p[c1];
      break;
    }
    c1++;
  }

  /* write sum to file and exit  */
  out=fopen(OUTPUT, "w");
  fprintf(out, "%lu\n", sum);
  fclose(out);
  return 0;
}
