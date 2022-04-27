#include <stdio.h>
#include <stdlib.h>

void criaMatriz() // Função para criar matriz 3d
{
  // Declaração de matriz e suas dimensões
  int ***matriz;
  int x, y, z, i, j, k, r1, r2, r3;

  // Número de linhas
  printf("Digite o número de linhas:");
  scanf("%d", &y);

  // Número de colunas
  printf("Digite o número de colunas:");
  scanf("%d", &z);

  // Profundidade do paralelepipedo
  printf("Digite a largura do paralelepipedo:");
  scanf("%d", &x);

  // Raios do elipsoide
  printf("Raio 1:");
  scanf("%d", &r1);

  printf("Raio 2:");
  scanf("%d", &r2);

  printf("Raio 3:");
  scanf("%d", &r3);

  // Alocação dinâmica da matriz
  matriz = malloc(x * sizeof(int **));

  for (i = 0; i < x; i++)
  {
    matriz[i] = malloc(y * sizeof(int *));
  }

  for (i = 0; i < x; i++)
  {
    for (j = 0; j < y; j++)
    {
      matriz[i][j] = malloc(z * sizeof(int));
    }
  }

  // Declaração do centro da elipsoide
  float m_centro_x = x / 2;
  float m_centro_y = y / 2;
  float m_centro_z = z / 2;

  // Iteração que verifica se a posição da matriz está dentro do elipsoide
  for (i = 0; i < x; i++)
  {
    for (j = 0; j < y; j++)
    {
      for (k = 0; k < z; k++)
      {
        if (pow(((i - m_centro_x) / r1), 2) + pow(((j - m_centro_y) / r2), 2) + pow(((k - m_centro_z) / r3), 2) <= 1)
        {
          matriz[i][j][k] = 1;
        }
        else
        {
          matriz[i][j][k] = 0;
        }
      }
    }
  }

  // Seleção do plano que será mostrado
  int plano_escolhido;
  printf("Qual plano deseja ver:");
  scanf("%d", &plano_escolhido);

  // Print do plano selecionado
  for (j = 0; j < y; j++)
  {
    for (k = 0; k < z; k++)
    {
      printf("%2d ", matriz[plano_escolhido][j][k]);
    }
    printf("\n");
  }
  printf("\n");

  // Liberar a memória da matriz alocada anteriormente
  for (i = 0; i < x; i++)
  {
    for (j = 0; j < y; j++)
    {
      free(matriz[i][j]);
    }
  }
  for (i = 0; i < x; i++)
  {
    free(matriz[i]);
  }

  free(matriz);
}

int main()
{
  criaMatriz(); // Chama a função
  return 0;
}
