/*
ID: talos
LANG: C
PROG: friday
*/

#include <stdio.h>

#define INPUT  "friday.in"
#define OUTPUT "friday.out"
#define RETURN_SUCCESS 0


int main (void)
{    
/* definitions */
  unsigned short int n , year , leap , day , result[7] ;
  int c , c2 ;
  FILE *in , *out ;

  /* initialization */
  int m[13] = { 0 , 31, 28 , 31 , 30 , 31 , 30 ,
  31 , 31 , 30 , 31 , 30 ,31 };
  for (c=0;c<8;c++)
  {
      result[c]= 0 ;
  }

  /* open file and read the number*/
  in  = fopen (INPUT , "r");
  fscanf (in , "%d" , &n);
  fclose (in);
  year = 1900 ; day=0 ; /* Sunday 31-12-1899 */
     
  for (c2 = year ; c2 < year+n ; c2++)
    {
       leap = c2%4 == 0 && c2%100 !=0 || c2%400 == 0 ;
       m[2]+=leap ;
  for (c=1;c<13;c++)
    {
      day=(day+13)%7 ;
      result[day]++ ;
      day= (day+m[c]-13)%7 ;
    }
       m[2]=28 ; /* restore february days*/
    }
  
  /* write data to output file */
  out  = fopen (OUTPUT , "w");
    fprintf( out ,"%d " , result[6]);
  for (c=0;c<5;c++)
  {
      fprintf( out , "%d " , result[c]);
  }
  fprintf( out ,"%d\n" , result[5]);
  fflush(out) ; fclose (out); 

    return (RETURN_SUCCESS);
}
