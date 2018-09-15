/*
ID: talos
LANG: C
PROG: barn1
 */

#define INPUT "barn1.in"     /* input file*/
#define OUTPUT "barn1.out"   /* output file*/

#include <stdio.h>

int getmax(int[] , int );

int main ()
{
  /* definitions */
  int m , s , c;
  int c1, c2 , key ;
  int result ;
  FILE *in , *out;

  /* read m, s, c*/
  in=fopen(INPUT, "r");
  fscanf(in, "%d %d %d\n", &m, &s, &c);
  int os[c] , gap[c];

  /* read the rest data */
  for (c1=0; c1 < c; c1++)
  {
    fscanf(in, "%d\n", (os + c1));
  }
  fclose(in);

  /* insertion sort */
  for (c1 = 1; c1 < c; c1++)
  {
    key = os[c1];
    c2 = c1 - 1;
    while ((c2>-1) && (os[c2] > key))
    {
      os[c2 + 1] = os[c2];
      c2--;
    }
    os[c2 + 1 ] = key;
  }

  for (c1=0; c1 < c; c1++)
  {
    gap[c1]=0;
  }
  /* find the gaps*/
  for (c1=0; c1 < c - 1; c1++)
  {
    gap[c1]=os[c1 + 1] - os[c1] - 1;
  }
  /* compute result */
  for (c1=1 , result=os[c - 1] - os[0] + 1 ; c1 < m; c1++)
  {
    c2=getmax(gap , c ); /* biggest gap */
    result-=c2;
  }

  if (m > c)
  {
    result=c;
  }
  /* write result to file*/
  out=fopen(OUTPUT, "w");
  fprintf (out , "%d\n", result);
  fclose(out);
  return (0);
}

int getmax (int array[] , int len)
{
  int max , c , flag ;
  for (c=0 , max=0; c < len; c++)
  {
    if (max < array[c])
    {
      max=array[c];
      flag=c;
    }
  }
  array[flag]=-1;
  return max;
}