/*
ID: talos
LANG: C
PROG: beads
 */

#include <stdio.h>

#define INPUT  "beads.in"
#define OUTPUT "beads.out"

#define BLUE   98
#define RED    114
#define WHITE  119
#define MAX    700

main ()
{
    /* definitions */
    unsigned short int n, c1, c2, cur, flag, lastcolor, point ,sum, result;
    char beads[MAX];
    FILE *in, *out;

    /* initialization */
    result = 0;

    /* read input file to a string*/
    in = fopen (INPUT, "r");
    fscanf (in, "%d", &n);
    fscanf (in, "%s", beads);

    /* open file for output data */
    out = fopen (OUTPUT, "w");
    /* if no red or blue exists , then result=n */
    for (c1 = 0, flag = 0; c1 < n; c1++)
      {
        cur = (int) beads[c1];

        if (cur == BLUE)
          {
            flag++;
            break;
          }
      }
    for (c1 = 0; c1 < n; c1++)
      {
        cur = (int) beads[c1];

        if (cur == RED)
          {
            flag++;
            break;
          }

      }
    if (flag != 2)
      {
        result = n;
        fprintf (out, "%d\n", result);
        fclose (out);
        return 0;
      }
    /* double the array*/
    for (c1 = 0; c1 < n; c1++)
      {
        beads[c1 + n] = beads[c1];
      }
  

    for (c1 = 0, sum = 0, lastcolor = 0, flag = 0; c1 < 2 * n; c1++)
      {

        cur = beads[c1];
        if (cur == WHITE)
          {
            sum++;
            continue ;
          }
        if (cur == BLUE)
          {
            sum++;
            if (lastcolor == 2) /* it was red*/
              {
                flag++;
                point= c1;
              }
            lastcolor = 1; /* it is blue */
            if (flag == 2)
              {
                /* end of circle*/
                sum--; flag=0 ; lastcolor=0;
                if (sum>result)
                  {
                    result=sum ;
                  }
                /* call last pointer*/
                c1 = point ; sum=0;
                }
            continue ;

          }

        if (cur == RED)
          {
            sum++;
            if (lastcolor == 1) /* it was blue*/
              {
                flag++;
                point= c1;
              }
            lastcolor = 2; /* it is red */
            if (flag == 2)
              {
                /* end of circle*/
                sum--; flag=0; lastcolor=0;
                if (sum>result)
                  {
                    result=sum ;
                  }
                /* call last pointer*/
                c1 = point ; sum=0;
                }
          }

      }
    if (result>n)
      {
        result=n;
      }
    /* print result to file*/
    fprintf (out, "%d\n", result);

    /* close files and exit*/
    fclose (out);
    fclose (in);
    return (0);
}
