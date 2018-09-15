/*
ID: talos
LANG: C
PROG: palsquare
 */

#define INPUT "palsquare.in"     /* input file*/
#define OUTPUT "palsquare.out"   /* output file*/
#define MAX 300

#include <stdio.h>
#include <string.h>

char *convert_base (int , int ) ;
int check_pal(char[]) ;

int main ()
{
  unsigned short int  b , res ;
  unsigned long int c , pal;
  char sc[35];
  char *spal;
  FILE *in, *out;
  /* read base B*/
  in=fopen(INPUT, "r");
  fscanf(in, "%d", &b);
  fclose (in);
  out=fopen(OUTPUT, "w");

  /* for n=1 to 300*/
  for (c=1; c < MAX + 1; c++)
  {
    /* compute n*n (decimal system) */
    pal=c*c;
    /* convert from base 10 to base B and
     * check if it is a palindrome 
     */

    strcpy(sc, convert_base(c, b ));
    spal= convert_base(pal, b );
    res=check_pal(spal);
    /* if it is , write to file*/
    if (res == 1)
    {
      fprintf(out , "%s %s\n", sc , spal);
    }
    /* else , compute next n*/
  }
  /* close files end exit*/
  fclose(out);
  return (0);
}

char *convert_base (int number , int base  )
{
  /* idea taken from Robert Jan Schaper */
  static char buffer[35]={0};
  int h = 30;
  for (; number && h ; --h, number /= base)
  {
    buffer[h] = "0123456789ABCDEFGHIJ"[number % base];
  }

  return &buffer[h + 1];
}

int check_pal(char string[])
{/* function returns 1 if it is a palindrome , 0 if it isn't */
  int c ;
  int left , right , len;
  /* get length of string */
  len=0;
  for (c=0; string[c] != '\0'; c++)
  {
    len++;
  }
  for (left=0 , right=len - 1; left < right; left++, right--)
  {
    if (string[left] != string[right])
    {
      return 0;
    }
  }

  return 1;
}