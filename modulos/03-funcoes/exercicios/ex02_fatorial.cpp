// Exercício 02 — Fatorial recursivo
//
// 5! = 5 * 4 * 3 * 2 * 1 = 120
// Use recursão: fatorial(0) e fatorial(1) são 1.
// Devolva 0 para números negativos.
#include "teste.hpp"

long long fatorial(int n) {
    // TODO
    return 0;
}

int main() {
    CHECK_IGUAL(1LL, fatorial(0));
    CHECK_IGUAL(1LL, fatorial(1));
    CHECK_IGUAL(6LL, fatorial(3));
    CHECK_IGUAL(120LL, fatorial(5));
    CHECK_IGUAL(3628800LL, fatorial(10));
    CHECK_IGUAL(0LL, fatorial(-1));
    return teste::resumo("ex02 · fatorial");
}
