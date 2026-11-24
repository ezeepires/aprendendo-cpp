// Exercício 04 — Número primo
//
// Primo: maior que 1 e divisível apenas por 1 e por ele mesmo.
// Dica: teste divisores de 2 até a raiz quadrada (i * i <= n).
#include "teste.hpp"

bool eh_primo(long long n) {
    // TODO
    return false;
}

int main() {
    CHECK(!eh_primo(-7));
    CHECK(!eh_primo(0));
    CHECK(!eh_primo(1));
    CHECK(eh_primo(2));
    CHECK(eh_primo(3));
    CHECK(!eh_primo(4));
    CHECK(eh_primo(97));
    CHECK(!eh_primo(100));
    CHECK(eh_primo(7919));
    return teste::resumo("ex04 · primo");
}
