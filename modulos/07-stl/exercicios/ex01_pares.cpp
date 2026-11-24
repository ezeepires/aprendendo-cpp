// Exercício 01 — Filtrar pares
//
// Devolva um novo vetor só com os números pares, NA MESMA ORDEM.
// {4, 7, 2, 9, 10} → {4, 2, 10}
// Sugestão: std::copy_if com std::back_inserter.
#include <algorithm>
#include <iterator>
#include <vector>
#include "teste.hpp"

std::vector<int> pares(const std::vector<int>& valores) {
    // TODO
    return {};
}

int main() {
    CHECK(pares({4, 7, 2, 9, 10}) == std::vector<int>({4, 2, 10}));
    CHECK(pares({1, 3, 5}) == std::vector<int>({}));
    CHECK(pares({}) == std::vector<int>({}));
    CHECK(pares({0, -2, -3}) == std::vector<int>({0, -2}));
    CHECK(pares({8}) == std::vector<int>({8}));
    return teste::resumo("ex01 · pares");
}
