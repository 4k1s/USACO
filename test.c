/*
ID: talos
LANG: C
TASK: test
*/

/* not my code but from "The First Challenge" tutorial */

#include <stdio.h>
main () {
    FILE *fin  = fopen ("test.in", "r");
    FILE *fout = fopen ("test.out", "w");
    int a, b;
    fscanf (fin, "%d %d", &a, &b);	/* the two input integers */
    fprintf (fout, "%d\n", a+b);
    return (0);                         /* changed exit() to return () */
}
