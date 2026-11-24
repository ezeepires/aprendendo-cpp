// Exercício 04 — Trocar valores
//
// trocar(a, b) deve inverter os valores das duas variáveis.
// Use referências: o efeito precisa ser visível em main.
//
// Desafio extra: faça sem variável temporária (a ^= b; b ^= a; a ^= b;)
#include "teste.hpp"

void trocar(int& a, int& b) {
    // TODO
}

int main() {
    int x = 1, y = 2;
    trocar(x, y);
    CHECK_IGUAL(2, x);
    CHECK_IGUAL(1, y);

    int p = -10, q = 10;
    trocar(p, q);
    CHECK_IGUAL(10, p);
    CHECK_IGUAL(-10, q);

    int z = 7;
    trocar(z, z);          // trocar consigo mesmo não pode quebrar
    CHECK_IGUAL(7, z);
    return teste::resumo("ex04 · trocar");
}
