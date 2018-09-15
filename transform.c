/*
ID: talos
LANG: C
PROG: transform
 */

#define INPUT "transform.in"     /* input file*/
#define OUTPUT "transform.out"   /* output file*/


#include <stdio.h>

int rotate(char *, int);
int reflect(char *, int);
int copy_array(char *, char *, int);
int compare_array(char *, char *, int);

int main()
{
  int c1, c2;
  unsigned char n, size, cur;
  FILE *in, *out;

  /* open file for reading*/
  in = fopen(INPUT, "r");

  fscanf(in, "%d\n", &n);

  size = n*n;
  unsigned char array1[size], array2[size], copy[size];

  /* read original array*/
  for (c1 = 0, c2 = 0; c1 < n * (n + 1); c1++, c2++)
  {
    cur = getc(in);

    if (cur == '\n')
    {
      c2--;
      continue;
    }
    array1[c2] = cur;
  }

  /* read transformed array*/
  for (c1 = 0, c2 = 0; c1 < n * (n + 1); c1++, c2++)
  {
    cur = getc(in);

    if (cur == '\n')
    {
      c2--;
      continue;
    }
    array2[c2] = cur;
  }
  fclose(in);


  /* special case : n=1*/
  if (n == 1)
  {
    if (array1[0] == array2[0])
    {
      c1=1;
    } else
    {
      c1=7;
    }
    out = fopen(OUTPUT, "w");
    fprintf(out, "%d\n", c1);
    fclose(out);
    return 0;
  }

  copy_array(array1, copy, n);

  /*open file for writing */
  out = fopen(OUTPUT, "w");

  for (c1 = 1; c1 < 4; c1++)
  {
    rotate(copy, n);
    if (c2 = compare_array(array2, copy, n))
    {
      fprintf(out, "%d\n", c1);
      fclose(out);
      return 0;
    }
  }
  copy_array(array1, copy, n);
  reflect(copy, n);
  if ( compare_array(array2, copy, n))
  {
    fprintf(out, "%d\n", 4);
    fclose(out);
    return 0;
  }

  for (c1 = 1; c1 < 4; c1++)
  {
    rotate(copy, n);
    if (c2 = compare_array(array2, copy, n))
    {
      fprintf(out, "%d\n", 5);
      fclose(out);
      return 0;
    }
  }

  if (compare_array(array1, array2, n))
  {
    fprintf(out, "%d\n", 6);
    fclose(out);
    return 0;
  }

  fprintf(out, "%d\n", 7);
  fclose(out);
  return 0;
}

int rotate(char arr[], int n)
{
  int c1, c2;
  char rot[n * n];
  for (c2 = 0; c2 < n; c2++)
  {
    for (c1 = 0; c1 < n; c1++)
    {
      rot[c1 * n + n - 1 - c2] = arr[n * c2 + c1];
    }
  }
  copy_array(rot, arr, n);

  return 0;
}

int reflect(char arr[], int n)
{
  int c1, c2;
  char ref[n * n];
  rotate(arr, n);
  rotate(arr, n);
  for (c2 = 1; c2 <= n / 2; c2++)
  {
    for (c1=0; c1 < n; c1++)
    {
      ref[(n - c2) * n + c1]=arr[n * (c2 - 1) + c1];
    }
  }

  for (c2 = n; c2 > n / 2; c2--)
  {
    for (c1=0; c1 < n; c1++)
    {
      ref[(n - c2) * n + c1]=arr[n * (c2 - 1) + c1];
    }
  }
  copy_array(ref, arr, n);
  return 0;
}

int copy_array(char src[], char dest[], int len)
{
  int c;
  for (c = 0; c < len * len; c++)
  {
    dest[c] = src[c];
  }
  return 0;

}

int compare_array(char src[], char dest[], int len)
{
  int c;
  for (c = 0; c < len * len; c++)
  {
    if (src[c] != dest[c])
    {
      return 0; /* arrays differ */
    }
  }
  return 1; /* arrays match */
}