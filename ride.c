/*
ID: talos
LANG: C
PROG: ride
*/

/* This is my first try for USACO
 * Ok , let's do it!
 */

#include <stdio.h>
#include <string.h>         /* for strlen() */

#define INPUT "ride.in"     /* input file*/
#define OUTPUT "ride.out"   /* output file*/
#define MAX 7
#define REM 47


int main ()
{
    FILE *in , *out; 
    char comet_name[MAX] , group_name[MAX];
    unsigned long int comet , group , rem1 , rem2 ;
    int curchar , c;

    in = fopen ( INPUT , "r");
    fscanf (in,"%s",&comet_name);
    fscanf (in,"%s",&group_name);

    for (c = 0 , comet = 1; c< strlen(comet_name) ;c++)
    {
    curchar = (int) comet_name[c]-64;
    comet *= curchar ;
    }
    
    for (c = 0 , group = 1; c< strlen(group_name) ;c++)
    {
    curchar = (int) group_name[c]-64;
    group *= curchar ;
    }

    rem1 = comet % REM ;
    rem2 = group % REM ;

    out = fopen ( OUTPUT , "w");
        
 if ( rem1 == rem2 )
     fprintf ( out , "GO\n") ;
     else
     fprintf ( out ,"STAY\n") ;
    fclose (out); fclose (in) ;
    return (0);
}
