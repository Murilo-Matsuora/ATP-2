// Guilherme Uekita, Gustavo Magalhães e Murilo Matruora
#include "matriz.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
    Funções da matriz com ponteiro duplo
------------------------------------------------------------------------------*/

/*
    Inicializa mtz.
*/
mtz new_mtz(int lin, int col, float init) {
  mtz m;

  if (lin > 0 && col > 0) {
    m.lin = lin;
    m.col = col;
    // Alocação das linhas: aloca ponteiros simples
    m.data = malloc(lin * sizeof(float *));
    if (m.data != NULL) {
      // Alocação das colunas: aloca variável comum
      for (int i = 0; i < lin; i++) {
        m.data[i] = malloc(col * sizeof(float));
        if (m.data[i] != NULL)
          // Inicialização das entradas
          for (int j = 0; j < col; j++) {
            m.data[i][j] = init;
          }
        else {
          printf("Memória insuficiente para alocação.");
        }
      }
    } else {
      printf("Memória insuficiente para alocação.");
    }
  } else {
    m.lin = 0;
    m.col = 0;
    m.data = NULL;
  }

  return m;
}

/*
    Checa se alguma das alocações de mtz falhou.
*/
bool mtz_is_null(mtz m) {
  if (m.data == NULL) {
    return true;
  }
  for (int i = 0; i < m.lin; i++)
    if (m.data[i] == NULL) {
      return true;
    }
  return false;
}

/*
    Libera memória de mtz. Para cada malloc, é feito um free.
*/
void free_mtz(mtz *m) {
  if (m->data != NULL) {
    for (int i = 0; i < m->lin; i++) {
      if (m->data[i] != NULL) {
        free(m->data[i]);
      }
    }
    free(m->data);
    m->data = NULL;
  }
}

/*
    Pede para usuário inserir elementos na matriz.
*/
void mtz_read(mtz m) {
  if (mtz_is_null(m)) {
    printf("Matriz é NULL.");
    return;
  }

  for (int i = 0; i < m.lin; i++)
    for (int j = 0; j < m.col; j++) {
      printf("Digite a entrada [%d,%d]: ", i, j);
      scanf("%f", &m.data[i][j]);
    }
}

/*
    Imprime na tela os elementos da matriz.
*/
void mtz_print(mtz m) {
  if (mtz_is_null(m)) {
    printf("Matriz é NULL.\n");
    return;
  }

  for (int i = 0; i < m.lin; i++) {
    for (int j = 0; j < m.col; j++) {
      printf("%f ", m.data[i][j]);
    }
    printf("\n");
  }
}

/*
    Soma de duas matrizes
*/
mtz soma_mtz(mtz A, mtz B) {
  if (!mtz_is_null(A) && !mtz_is_null(B)) {
    if (A.lin == B.lin && A.col == B.col) {
      mtz res = new_mtz(A.lin, A.col, 0);
      if (mtz_is_null(res)) {
        printf("Memória insuficiente para matriz de resultado.");
        return new_mtz(0, 0, 0);
      }
      for (int i = 0; i < A.lin; i++)
        for (int j = 0; j < A.col; j++) {
          res.data[i][j] = A.data[i][j] + B.data[i][j];
        }
      return res;
    }
    printf("Matrizes incompatíveis para soma.");
    return new_mtz(0, 0, 0);
  }
  printf("Matriz de entrada é null.");
  return new_mtz(0, 0, 0);
}

// Multiplicação de matriz por escalar
mtz ppscalar_mtz(mtz m, float num) {
  if (!mtz_is_null(m)) {
    mtz res = new_mtz(m.lin, m.col, 0);
    if (mtz_is_null(res)) {
      printf("Memória insuficiente para matriz de resultado.");
      return new_mtz(0, 0, 0);
    }
    for (int i = 0; i < m.lin; i++)
      for (int j = 0; j < m.col; j++) {
        res.data[i][j] = m.data[i][j] * num;
      }
    return res;
  }
  printf("Matriz de entrada é null.");
  return new_mtz(0, 0, 0);
}

// Transposta da matriz dada
mtz transposta_mtz(mtz m) {
  if (!mtz_is_null(m)) {
    mtz res = new_mtz(m.col, m.lin, 0);
    if (mtz_is_null(res)) {
      printf("Memória insuficiente para matriz de resultado.");
      return new_mtz(0, 0, 0);
    }
    for (int i = 0; i < m.lin; i++)
      for (int j = 0; j < m.col; j++) {
        res.data[j][i] = m.data[i][j];
      }
    return res;
  }
  printf("Matriz de entrada é null.");
  return new_mtz(0, 0, 0);
}

// Multiplicação de matrizes
mtz mul_mtz(mtz A, mtz B) {
  if (!mtz_is_null(A) && !mtz_is_null(B)) {
    // Condição para que a multiplicação de matrizes seja possível
    if (A.col == B.lin) {
      mtz res = new_mtz(A.lin, B.col, 0);
      if (mtz_is_null(res)) {
        printf("Memória insuficiente para matriz de resultado. \n");
        return new_mtz(0, 0, 0);
      }
      for (int i = 0; i < res.lin; i++)
        for (int j = 0; j < res.col; j++) {
          for (int k = 0; k < A.col; k++)
            res.data[i][j] += A.data[i][k] * B.data[k][j];
        }
      return res;
    }
    printf("Matrizes incompatíveis para multiplicação. \n");
    return new_mtz(0, 0, 0);
  }
  printf("Matriz de entrada é null.");
  return new_mtz(0, 0, 0);
}
