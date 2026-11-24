// Exercício 03 — Ordenar decrescente
//
// Devolva o vetor ordenado do maior para o menor.
// Dica: std::sort com std::greater<> ou uma lambda.
#include <algorithm>
#include <vector>
#include "teste.hpp"

std::vector<int> ordenar_decrescente(std::vector<int> valores) {
    // TODO
    return valores;
}

int main() {
    CHECK(ordenar_decrescente({3, 1, 4, 1, 5}) ==
          std::vector<int>({5, 4, 3, 1, 1}));
    CHECK(ordenar_decrescente({}) == std::vector<int>({}));
    CHECK(ordenar_decrescente({7}) == std::vector<int>({7}));
    CHECK(ordenar_decrescente({-1, -5, 0}) == std::vector<int>({0, -1, -5}));
    return teste::resumo("ex03 · decrescente");
}
