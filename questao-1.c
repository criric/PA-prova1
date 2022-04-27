#include <stdio.h>
#include <stdlib.h>

void criaMatriz() // Function to create 3d matrix
{
  int ***m;
  int x, y, z, i, j, k, r1, r2, r3;

  // Number of lines
  printf("Digite o número de linhas:");
  scanf("%d", &y);

  // Number of columns
  printf("Digite o número de colunas:");
  scanf("%d", &z);

  // depth
  printf("Digite a largura do paralelepipedo:");
  scanf("%d", &x);

  printf("Raio 1:");
  scanf("%d", &r1);

  printf("Raio 2:");
  scanf("%d", &r2);

  printf("Raio 3:");
  scanf("%d", &r3);

  m = malloc(x * sizeof(int **));

  for (i = 0; i < x; i++)
  {
    m[i] = malloc(y * sizeof(int *));
  }

  for (i = 0; i < x; i++)
  {
    for (j = 0; j < y; j++)
    {
      m[i][j] = malloc(z * sizeof(int));
    }
  }

  float m_centro_x = x / 2;
  float m_centro_y = y / 2;
  float m_centro_z = z / 2;

  for (i = 0; i < x; i++)
  {
    for (j = 0; j < y; j++)
    {
      for (k = 0; k < z; k++)
      {
        if (pow(((i - m_centro_x) / r1), 2) + pow(((j - m_centro_y) / r2), 2) + pow(((k - m_centro_z) / r3), 2) <= 1)
        {
          m[i][j][k] = 1;
        }
        else
        {
          m[i][j][k] = 0;
        }
      }
    }
  }

  for (i = 0; i < x; i++)
  {
    for (j = 0; j < y; j++)
    {
      for (k = 0; k < z; k++)
      {
        printf("%2d ", m[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }

  for (i = 0; i < x; i++)
  {
    for (j = 0; j < y; j++)
    {
      free(m[i][j]);
    }
  }
  for (i = 0; i < x; i++)
  {
    free(m[i]);
  }

  free(m);
}

int main()
{
  criaMatriz();
  return 0;
}
