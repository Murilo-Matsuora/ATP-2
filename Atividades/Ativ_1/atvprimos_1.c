// Guilherme Uekita, Gustavo Magalhães e Murilo Matsuora
#include <cmath>
#include <iostream>

bool primo_r(int n, int i) {
  if (n == 2) // 2 é o único número par que é primo
    return true;
  if (n % 2 == 0 && n != 2) // Pares além de 2 não são primos.
    return false;
  /* Quando n não for divisível por exatamente 2
   números (ele próprio e 1), n não será primo */
  if (n == 1 || (n % i == 0 && n != i))
    return false;
  /* Quando o quadrado de i é maior que o número e as outras
   condições não foram atendidas, o número é primo */
  if (i * i > n)
    return true;
  // A linha abaixo só é rodada caso os ifs anteriories foram falsos
  return primo_r(n, i + 2);
}

bool primo_i(int n) {
  if (n % 2 == 0 && n != 2) // Pares além de 2 não são primos.
    return false;
  bool flag = true;
  if (n == 1) // 1 não é primo pois é divisível por apenas 1 número, ele próprio
    return false;
  for (int i = 3; i <= sqrt(n); i += 2) {
    /* Se i > sqrt(n), a análise se encerrará, pois
    nenhum número após a raiz dividirá n */
    if (n % i == 0 && n != i) {
      flag = false;
      break;
    }
  }
  return flag;
}

int main() {
  int n = 0;

  printf("Digite um numero inteiro positivo para verificar se eh primo: ");
  scanf("%d", &n);
  while (n <= 0) {
    printf("O numero escolhido nao eh um inteiro positivo.\n");
    printf("Insira outro numero: ");
    scanf("%d", &n);
  }

  if (primo_i(n))
    printf("Metodo iterativo: o numero eh primo. \n");
  else
    printf("Metodo iterativo: o numero nao eh primo. \n");

  if (primo_r(n, 3))
    printf("Metodo recursivo: o numero eh primo. \n");
  else
    printf("Metodo recursivo: o numero nao eh primo. \n");
}
