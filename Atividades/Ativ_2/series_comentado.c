// Guilherme Uekita, Gustavo Magalhães e Murilo Matsuora
#include <stdio.h>

float soma(float (*serie)(int), int N) { //Função que recebe como argumentos o endereço de uma das 3 séries e um N número de iterações. O endereço é recebido por um ponteiro, o que permite que este modifique o conteúdo daquele.
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

  printf("%f\n", soma(&serie1, N)); //São enviados o endereço da função e o número de iterações para a função "soma".
  printf("%f\n", soma(&serie2, N));
  printf("%f\n", soma(&serie3, N));
}
