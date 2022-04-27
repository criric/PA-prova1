#include <stdio.h>
#include <stdlib.h>

void printbyte(unsigned char c)
{
  unsigned char i;
  unsigned char and;
  for (i = 128; i > 0; i = i >> 1)
  {
    and = i & c;
    if (and)
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

  // Declaro matriz, ponteiro e variável utilizada para representar o número inteiro
  unsigned char **matriz;
  unsigned char *px;
  unsigned long long int state;
  int i, j;
  int x = 8;
  int y = 8;
  state = 0;
  px = &state;

  // faço alocação dinâmica da matriz
  matriz = (unsigned char **)malloc(x * sizeof(unsigned char *));
  matriz[0] = (unsigned char *)malloc(x * y * sizeof(unsigned char));

  for (i = 1; i < x; i++)
  {
    matriz[i] = matriz[i - 1] + x;
  }

  // Preencho a matriz com 0 e 1
  for (i = 0; i <= 7; i++)
  {
    for (j = 0; j <= 7; j++)
    {
      matriz[i][j] = rand() % 2;
    }
  }

  // Printo minha matriz
  for (i = 0; i <= 7; i++)
  {
    for (j = 0; j <= 7; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  // Faço as iterações para que a variável soma receba o valor de cada linha, para depois passar para a variável state
  unsigned long long soma = 0;

  for (i = 7; i >= 0; i--)
  {
    for (j = 7; j >= 0; j--)
    {
      unsigned long long aux = matriz[i][j];
      soma += aux << 7 - j;
    }
    state += soma << 8 * (7 - i);
    soma = 0;
  }

  // Printo a sequência de bytes
  for (i = 7; i >= 0; i--)
  {
    printbyte(px[i]);
    printf("|");
  }

  // libero a matriz
  for (i = 1; i <= 7; i++)
  {
    free(matriz[i]);
  }
  free(matriz);
  return 0;
}