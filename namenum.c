/*
ID: talos
LANG: C
PROG: namenum
 */

#define INPUT "namenum.in"     /* input file*/
#define OUTPUT "namenum.out"   /* output file*/
#define MAX     13

#include <stdio.h>
#include <stdlib.h> /* for bsearch() */
#include <string.h> /* for strcmp() */

int convert (char * , int) ;
static int  cmpstringp(const void *, const void *);

int main ()
{
  char *bs , *name;
  name = (char*) calloc(MAX, sizeof (char) );
  bs=(char*) calloc(MAX, sizeof (char) );
  char code[MAX] , *result [100];
  result [100]=(char*) calloc(MAX, sizeof (char) );
  unsigned long int c, c2, c3, flag , len , lines ;
  FILE *in, *out;

  /* read input */
  in=fopen(INPUT, "r");
  fscanf(in, "%s", code);
  fclose (in);
  in=fopen("dict.txt" , "r");

  /* get length of code */
  c=0 ;
  c3=0;
  len=0;

  while (code[c] != '\0')
  {
    len++;
    c++;
  }

  /* get lines of the dictionary */
  lines=0;
  while (1)
  {
    c=fgetc(in);
    if (c == '\n')
    {
      lines++;
    }
    if (c == EOF)
    {
      break;
    }
  }
  rewind(in);
  char dict[lines][MAX];

  for (c=0; c < lines; c++)
  {
    fscanf (in, "%s", dict[c]);
  }
  fclose (in);

  /* write name to file */
  out=fopen(OUTPUT, "w");

  convert (code, len);
  for (c=0; c < len; c++)
  {
    name[c]=code[c];
  }
  name[len]='\0';

  c=0;
  flag=0;

  while (name[len] == '\0')
  {
    c++;
    /* -Q */
    for (c2=0; c2 < len; c2++)
    {
      if (name[c2] == 'Q')

      {
        name[c2] = 'S';
      }
    }

    bs=NULL;
    bs=(char *) bsearch (name, dict, lines , MAX,
                         (int(*)(const void*, const void*) ) strcmp);
    if (bs != NULL)
    {
      flag=1;
      result[c3]=bs;
      c3++;
    }
    /* +Q */
    for (c2=0; c2 < len; c2++)
    {
      if (name[c2] == 'S')

      {
        name[c2] = 'Q';
      }
    }

    name[0]++;

    for (c2=0; c2 < len; c2++)
    {
      if (name[c2] == (code[c2] + 3))

      {
        name[c2]=code[c2];
        name[c2 + 1]++;
      }
    }
  }

  if (!flag)
  {
    result[c3]="NONE";
    c3++;
  }
  qsort(result, c3, sizeof (char *) , cmpstringp);
  for (c2=0; c2 < c3; c2++)
  {
    printf("%s\n", result[c2]);
  }
  /* write name to file */
  out=fopen(OUTPUT, "w");
  for (c2=0; c2 < c3; c2++)
  {
    fprintf(out, "%s\n", result[c2]);
  }
  fclose (out);
  return (0);
}

int convert (char code [] , int ln)
{
  int c;
  for (c=0; c < ln; c++)
  {
    code[c]='A' + (code[c] - '2')*3;
    if (code[c] >= 'Q')
    {
      code[c]++;
    }
  }

  return 0;
}

static int  cmpstringp(const void *p1, const void *p2)
{
  return strcmp(* (char * const *) p1, * (char * const *) p2);
}
