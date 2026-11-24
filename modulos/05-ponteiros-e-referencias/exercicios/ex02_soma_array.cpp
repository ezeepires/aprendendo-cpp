// Exercício 02 — Soma de array recebido como ponteiro
//
// `valores` aponta para `quantidade` inteiros na memória.
// Devolva a soma. Se valores for nullptr ou quantidade <= 0, devolva 0.
// Dica: valores[i] funciona igual a *(valores + i).
#include "teste.hpp"

int soma(const int* valores, int quantidade) {
    // TODO
    return 0;
}

int main() {
    int a[] = {1, 2, 3, 4};
    CHECK_IGUAL(10, soma(a, 4));

    int b[] = {-5, 5};
    CHECK_IGUAL(0, soma(b, 2));

    CHECK_IGUAL(0, soma(nullptr, 3));
    CHECK_IGUAL(0, soma(a, 0));

    int c[] = {42};
    CHECK_IGUAL(42, soma(c, 1));
    return teste::resumo("ex02 · soma de array");
}
