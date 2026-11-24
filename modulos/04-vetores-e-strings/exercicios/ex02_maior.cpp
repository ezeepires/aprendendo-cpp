// Exercício 02 — Maior elemento
//
// Devolva o maior valor do vetor, usando um laço (não use max_element).
// O vetor sempre terá pelo menos 1 elemento.
#include <vector>
#include "teste.hpp"

int maior(const std::vector<int>& valores) {
    // TODO
    return 0;
}

int main() {
    CHECK_IGUAL(9, maior({5, 3, 9, 1, 7}));
    CHECK_IGUAL(-1, maior({-5, -1, -9}));
    CHECK_IGUAL(42, maior({42}));
    CHECK_IGUAL(0, maior({0, -3, 0}));
    CHECK_IGUAL(100, maior({1, 2, 3, 100, 4}));
    return teste::resumo("ex02 · maior");
}
