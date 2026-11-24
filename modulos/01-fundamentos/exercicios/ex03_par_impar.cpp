// Exercício 03 — Par ou ímpar
//
// Implemente `eh_par` usando o operador de resto (%).
// Dica: números negativos também podem ser pares! -3 % 2 == -1.
#include "teste.hpp"

bool eh_par(int numero) {
    // TODO
    return false;
}

int main() {
    CHECK(eh_par(2));
    CHECK(eh_par(0));
    CHECK(eh_par(-4));
    CHECK(!eh_par(7));
    CHECK(!eh_par(-3));
    CHECK(!eh_par(1));
    return teste::resumo("ex03 · par ou ímpar");
}
