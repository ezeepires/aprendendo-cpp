// Exercício 04 — Mediana
//
// Ordene e pegue o elemento do meio.
// Ímpar: o do meio. Par: média dos dois do meio.
// {1, 3, 2}      → 2.0
// {1, 2, 3, 4}   → 2.5
// {}             → 0.0
#include <algorithm>
#include <vector>
#include "teste.hpp"

double mediana(std::vector<int> valores) {
    // TODO
    return 0.0;
}

int main() {
    CHECK_PROXIMO(2.0, mediana({1, 3, 2}), 0.0001);
    CHECK_PROXIMO(2.5, mediana({1, 2, 3, 4}), 0.0001);
    CHECK_PROXIMO(3.0, mediana({1, 2, 3, 4, 5}), 0.0001);
    CHECK_PROXIMO(0.0, mediana({}), 0.0001);
    CHECK_PROXIMO(10.0, mediana({10}), 0.0001);
    CHECK_PROXIMO(5.0, mediana({9, 1, 5, 5, 1, 9}), 0.0001);
    return teste::resumo("ex04 · mediana");
}
