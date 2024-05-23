// Guilherme Uekita, Gustavo Magalh�es e Murilo Matsuora
#include <cmath>
#include <iostream>

bool primo_r(int n, int i) {
  if (n == 2) // 2 � o �nico n�mero par que � primo
    return true;
  if (n % 2 == 0 && n != 2) // Pares al�m de 2 n�o s�o primos.
    return false;
  /* Quando n n�o for divis�vel por exatamente 2
   n�meros (ele pr�prio e 1), n n�o ser� primo */
  if (n == 1 || (n % i == 0 && n != i))
    return false;
  /* Quando o quadrado de i � maior que o n�mero e as outras
   condi��es n�o foram atendidas, o n�mero � primo */
  if (i * i > n)
    return true;
  // A linha abaixo s� � rodada caso os ifs anteriories foram falsos
  return primo_r(n, i + 2);
}

bool primo_i(int n) {
  if (n % 2 == 0 && n != 2) // Pares al�m de 2 n�o s�o primos.
    return false;
  bool flag = true;
  if (n == 1) // 1 n�o � primo pois � divis�vel por apenas 1 n�mero, ele pr�prio
    return false;
  for (int i = 3; i <= sqrt(n); i += 2) {
    /* Se i > sqrt(n), a an�lise se encerrar�, pois
    nenhum n�mero ap�s a raiz dividir� n */
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
