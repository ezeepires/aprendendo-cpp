// Exercício 02 — Soma genérica
//
// Implemente `soma` como template para qualquer vetor cujo tipo possa ser somado.
// Devolva T{} (valor inicializado) para vetor vazio.
#include <string>
#include <vector>
#include "teste.hpp"

// TODO: percorra o vetor somando os valores em um acumulador T
template <typename T>
T soma(const std::vector<T>& valores) {
    (void)valores;
    return T{};
}

int main() {
    CHECK_IGUAL(6, soma(std::vector<int>{1, 2, 3}));
    CHECK_IGUAL(0, soma(std::vector<int>{}));
    CHECK_PROXIMO(4.0, soma(std::vector<double>{1.5, 2.5}), 0.0001);
    CHECK_IGUAL(std::string("abc"), soma(std::vector<std::string>{"a", "bc"}));
    CHECK_IGUAL(-6, soma(std::vector<int>{-1, -2, -3}));
    return teste::resumo("ex02 · soma genérica");
}
