/*
ID: talos
LANG: C
PROG: dualpal
 */

#define INPUT "dualpal.in"     /* input file*/
#define OUTPUT "dualpal.out"   /* output file*/

#include <stdio.h>

char *convert_base (int , int ) ;
int check_pal(char[]) ;

int main ()
{
  unsigned int c, r, flag , s , n;
  FILE *in, *out;
  char *sss;

  /* read N,S */
  in=fopen(INPUT, "r");
  fscanf(in, "%u %u", &n , &s);
  fclose(in);
  out=fopen(OUTPUT, "w");

  /* while N>0 do*/
  while (n)
  {
    /* next number*/
    s++;
    flag=0;
    /* for c=2 to 10*/
    for (c=2; c < 11; c++)
    {
      /* convert (S+k) to base c*/
      sss=convert_base(s, c);
      r=check_pal(sss);
      /* inc flag if check-palindrom positive*/
      if (r)
      {
        flag++;

      }
      /* and write S+k to file if flag=2*/
      if (flag == 2)
      {
        fprintf(out, "%d\n", s);
        flag=0;
        n--;
        break;
      }
    }
    /* else check next*/
  }
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