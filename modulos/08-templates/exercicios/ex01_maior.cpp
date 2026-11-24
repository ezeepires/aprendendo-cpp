// Exercício 01 — Maior genérico
//
// Implemente um template `maior` que funcione com int, double e std::string.
// Use `template <typename T>` e o operador >.
#include <string>
#include "teste.hpp"

// TODO: troque a implementação por `return a > b ? a : b;`
template <typename T>
T maior(T a, T b) {
    (void)a;
    (void)b;
    return T{};
}

int main() {
    CHECK_IGUAL(7, maior(3, 7));
    CHECK_IGUAL(3.5, maior(3.5, 1.2));
    CHECK_IGUAL(std::string("bia"), maior(std::string("ana"), std::string("bia")));
    CHECK_IGUAL(-1, maior(-1, -5));
    return teste::resumo("ex01 · maior genérico");
}
