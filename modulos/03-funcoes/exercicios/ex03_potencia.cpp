// Exercício 03 — Potência com valor padrão
//
// potencia(3)    → 9      (expoente padrão 2)
// potencia(2, 10) → 1024
// Expoente 0 → 1. Expoente negativo → 0 (não vamos trabalhar com frações).
#include "teste.hpp"

int potencia(int base, int expoente = 2) {
    // TODO
    return 0;
}

int main() {
    CHECK_IGUAL(9, potencia(3));
    CHECK_IGUAL(25, potencia(5));
    CHECK_IGUAL(1024, potencia(2, 10));
    CHECK_IGUAL(1, potencia(7, 0));
    CHECK_IGUAL(-8, potencia(-2, 3));
    CHECK_IGUAL(0, potencia(3, -1));
    return teste::resumo("ex03 · potência");
}
