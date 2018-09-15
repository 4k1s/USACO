/*
ID: talos
LANG: C
PROG: milk2
 */

#include <stdio.h>
#include <stdlib.h>

#define INPUT "milk2.in"     /* input file*/
#define OUTPUT "milk2.out"   /* output file*/
#define MAX 5000

void swap (int *, int *);
unsigned int getmax (unsigned int *, unsigned int);

int main ()
{
    unsigned int n, key, maxend, temp, flag, result1, result2, resultmax, resultmin;
    unsigned int start_point, end_point;
    int c1, c2;

    FILE *in, *out;


    /* read the data from file */
    in = fopen (INPUT, "r");
    fscanf (in, "%d", &n);

    unsigned int start_t[n], end_t[n];

    for (c1 = 0; c1 < n; c1++)
      {
        fscanf (in, "%d %d", &start_t[c1], &end_t[c1]);

      }
    /* Initialize*/
    result1 = 0;
    resultmax = 0, resultmin = 0;

    /* isertion sort of array start_t*/
    for (c1 = 1; c1 < n; c1++)
      {
        key = start_t[c1];
        temp = end_t[c1];
        c2 = c1 - 1;

        while ((c2>-1) && start_t[c2] > key)

          {
            start_t[c2 + 1] = start_t[c2];
            end_t[c2 + 1] = end_t[c2];
            c2--;
          }
        start_t[c2 + 1 ] = key;
        end_t[c2 + 1 ] = temp;

      }

    /* compute results*/
    for (c1 = 0, c2 = 0, result1 = 0, result2 = 0, maxend = getmax (end_t, n);
        end_point != maxend; c1++)
      {
        c2 = c1;
        start_point = start_t[c2];
        end_point = end_t[c2];
        for (c1 = c2; c1 < n; c1++)
          {
            if (end_point < end_t[c1])
              {
                end_point = end_t[c1];
              }


            if (end_point < start_t[c1 + 1])
              {
                if ((c1 < n - 1) && (start_t[c1 + 1] - end_point > result2))
                  {
                    result2 = start_t[c1 + 1] - end_point;


                  }
                break;
              }
            if (end_point == maxend)
              {

                break;
              }
          }

        if (end_point - start_point > result1)
          {
            result1 = end_point - start_point;
          }
      }


    /* write results to file */
    out = fopen (OUTPUT, "w");
    fprintf (out, "%d %d\n", result1, result2);

    fclose (out);
    fclose (in);
    return (0);

}

void swap (int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

unsigned int getmax (unsigned int array[], unsigned int len)
{
    unsigned int c, max = 0;
    max = array[0];
    for (c = 1; c < len; c++)
      {
        if (max < array[c])
          {
            max = array[c];
          }
      }
    return max;
}