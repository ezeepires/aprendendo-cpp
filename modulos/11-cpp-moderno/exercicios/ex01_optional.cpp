// Exercício 01 — optional
//
// Converta texto em int devolvendo std::optional<int>.
// Texto inválido (vazio, com letras, com sobra) → std::nullopt.
// Dica: use std::stoi com posição e verifique se consumiu tudo;
// capture a exceção e devolva nullopt.
#include <optional>
#include <string>
#include "teste.hpp"

std::optional<int> para_inteiro(const std::string& texto) {
    // TODO
    return std::nullopt;
}

int main() {
    CHECK(para_inteiro("42").has_value());
    CHECK_IGUAL(42, para_inteiro("42").value_or(-1));
    CHECK_IGUAL(-7, para_inteiro("-7").value_or(0));
    CHECK_IGUAL(0, para_inteiro("0").value_or(1));

    CHECK(!para_inteiro("").has_value());
    CHECK(!para_inteiro("abc").has_value());
    CHECK(!para_inteiro("42abc").has_value());
    CHECK(!para_inteiro(" ").has_value());
    return teste::resumo("ex01 · optional");
}
