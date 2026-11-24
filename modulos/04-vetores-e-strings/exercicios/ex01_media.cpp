// Exercício 01 — Média de um vetor
//
// Devolva a média dos valores. Se o vetor estiver vazio, devolva 0.0.
// Dica: some com um laço (ou std::accumulate) e divida pelo size().
#include <vector>
#include "teste.hpp"

double media(const std::vector<double>& valores) {
    // TODO
    return 0.0;
}

int main() {
    CHECK_PROXIMO(2.0, media({1.0, 2.0, 3.0}), 0.0001);
    CHECK_PROXIMO(7.5, media({10.0, 5.0}), 0.0001);
    CHECK_PROXIMO(0.0, media({}), 0.0001);
    CHECK_PROXIMO(-1.0, media({-2.0, 0.0}), 0.0001);
    CHECK_PROXIMO(4.0, media({4.0}), 0.0001);
    return teste::resumo("ex01 · média");
}
