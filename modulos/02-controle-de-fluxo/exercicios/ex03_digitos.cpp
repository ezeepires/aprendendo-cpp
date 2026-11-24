// Exercício 03 — Contagem de dígitos
//
// Conte quantos dígitos tem um número inteiro.
// Exemplo: 12345 → 5, 7 → 1, 0 → 1, -987 → 3
// Dica: use while e divisão inteira por 10. Cuide do sinal: use long long
// e trabalhe com o valor absoluto.
#include "teste.hpp"

int contar_digitos(long long numero) {
    // TODO: use while
    return 0;
}

int main() {
    CHECK_IGUAL(1, contar_digitos(0));
    CHECK_IGUAL(1, contar_digitos(7));
    CHECK_IGUAL(5, contar_digitos(12345));
    CHECK_IGUAL(3, contar_digitos(-987));
    CHECK_IGUAL(10, contar_digitos(1000000000LL));
    return teste::resumo("ex03 · dígitos");
}
