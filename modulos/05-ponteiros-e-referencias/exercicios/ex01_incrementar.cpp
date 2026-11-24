// Exercício 01 — Incrementar via ponteiro
//
// Some 1 no valor apontado por `p`.
// Se `p` for nullptr, não faça nada (nunca desreferencie um ponteiro nulo!).
#include "teste.hpp"

void incrementar(int* p) {
    // TODO
}

int main() {
    int a = 5;
    incrementar(&a);
    CHECK_IGUAL(6, a);

    int b = -1;
    incrementar(&b);
    CHECK_IGUAL(0, b);

    incrementar(nullptr);   // não pode quebrar

    int c = 0;
    incrementar(&c);
    CHECK_IGUAL(1, c);
    return teste::resumo("ex01 · incrementar");
}
