#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printbyte(unsigned char c)
{
  unsigned char i;
  unsigned char cu;
  for (i = 128; i > 0; i = i >> 1)
  {
    cu = i & c;
    if (cu)
    {
      printf("1");
    }
    else
    {
      printf("0");
    }
  }
}

int main()
{
  int i, j;
  unsigned long long x = 0;
  unsigned char *px;

  unsigned char c[8][8];

  //  c = (unsigned char **)malloc(8 * sizeof(unsigned char));
  //
  //  for (i = 0; i < 8; i++)
  //  {
  //    c[i] = (unsigned char *)malloc(8 * sizeof(unsigned char));
  //  }

  for (i = 0; i < 8; i++)
  {
    for (j = 0; j < 8; j++)
    {
      c[i][j] = rand() % 2;
    }
  }

  int pot = 0;

  for (i = 4; i >= 0; i--)
  {
    for (j = 4; j >= 0; j--)
    {
      x = x + (pow(2, pot) * c[i][j]);
      pot++;
    }
    printf("|");
  }
  printf("\n");
  printf("%d\n", x);

  // printf("\n");
  // for (i = 7; i >= 0; i--)
  // {
  //   for (j = 7; j >= 0; j--)
  //   {
  //     printbyte(c[i][j]);
  //     printf("|");
  //   }
  // }
  printf("\n");
  return 0;
}