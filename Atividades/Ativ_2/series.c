// Guilherme Uekita, Gustavo Magalhães e Murilo Matsuora
#include <stdio.h>

float soma(float (*serie)(int), int N) {
  float sum = 0;
  for (int i = 0; i <= N; i++) {
    sum += serie(i);
  }
  return sum;
}

float serie1(int num) { return 1 / (float)((4 * num + 1) * (4 * num + 3)); }
float serie2(int num) { return 1 / (float)((num + 1) * (num + 1)); }
float serie3(int num) { return 1 / (float)((2 * num + 1) * (2 * num + 1)); }

int main() {
  int N;

  printf("Digite o número de iterações: ");
  scanf("%d", &N);

  printf("%f\n", soma(&serie1, N));
  printf("%f\n", soma(&serie2, N));
  printf("%f\n", soma(&serie3, N));
  
  return 0;
}
