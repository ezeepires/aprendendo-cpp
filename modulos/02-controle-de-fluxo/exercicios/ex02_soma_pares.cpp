// Exercício 02 — Soma dos pares
//
// Some todos os números PARES de 1 até n (inclusive).
// Exemplo: n = 10 → 2 + 4 + 6 + 8 + 10 = 30
// Se n <= 0, devolva 0.
#include "teste.hpp"

long long soma_pares(int n) {
    // TODO: use um for
    return 0;
}

int main() {
    CHECK_IGUAL(30LL, soma_pares(10));
    CHECK_IGUAL(2LL, soma_pares(2));
    CHECK_IGUAL(0LL, soma_pares(1));
    CHECK_IGUAL(0LL, soma_pares(0));
    CHECK_IGUAL(0LL, soma_pares(-5));
    CHECK_IGUAL(2450LL, soma_pares(99));  // 2+4+...+98
    return teste::resumo("ex02 · soma dos pares");
}
