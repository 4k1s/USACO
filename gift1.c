/*
ID: talos
LANG: C
PROG: gift1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT  "gift1.in"
#define OUTPUT "gift1.out"
#define BUF    256
#define MAX    10

main ()
{
    /* definitions */
    static char name [MAX] [BUF];
    static char temp [BUF];
    static unsigned short int np, c, c2, c3, money, pers, rem, acc;
    static int result [MAX];

    FILE *in, *out;

    /* read np */
    in = fopen (INPUT, "r");
    out = fopen (OUTPUT, "w");
    fscanf (in, "%d", &np);

    /* read and store names*/
    for (c = 0; c < np; c++)
      {
        fscanf (in, "%s", name[c]);
      }

    /* detect and compute result for all*/

    for (c = 0; c < np; c++)
      {
        /* find which friend gives*/
        fscanf (in, "%s", temp);
        for (c2 = 0; strcmp (name[c2], temp); c2++)
          {
            ;
          }

        /* how much and to how many friends*/
        fscanf (in, "%d", &money);
        fscanf (in, "%d\n", &pers);


        if (!pers)
          {
            /* no transfers! */
            continue;
          }
        rem = money % pers;
        acc = (money - rem) / pers;
        result[c2] -= (acc * pers);

        /* find which friends takes*/
        for (c3 = 0; c3 < pers; c3++)
          {
            fscanf (in, "%s", temp);

            for (c2 = 0; strcmp (name[c2], temp); c2++)
              {

                ;
              }
            result[c2] += acc;
          }
      }

    /* print result array to gift1.out file*/
    for (c = 0; c < np; c++)
      {
        fprintf (out, "%s %d\n", name[c], result[c]);
      }

    fclose (in);
    fflush (out);
    fclose (out);
    return (EXIT_SUCCESS);
}
