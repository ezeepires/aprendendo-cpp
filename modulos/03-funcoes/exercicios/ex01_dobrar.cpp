// Exercício 01 — Dobrar por referência
//
// Implemente `dobrar` para multiplicar o valor original por 2.
// A função recebe uma referência (int&), então a alteração deve
// aparecer na variável de quem chamou.
#include "teste.hpp"

void dobrar(int& valor) {
    // TODO
}

int main() {
    int a = 5;
    dobrar(a);
    CHECK_IGUAL(10, a);

    int b = -3;
    dobrar(b);
    CHECK_IGUAL(-6, b);

    int c = 0;
    dobrar(c);
    CHECK_IGUAL(0, c);
    return teste::resumo("ex01 · dobrar");
}
