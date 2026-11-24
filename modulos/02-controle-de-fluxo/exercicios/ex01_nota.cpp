// Exercício 01 — Conceito pela nota
//
// 90+ → "A" | 80+ → "B" | 70+ → "C" | 60+ → "D" | abaixo de 60 → "F"
// Notas fora de 0..100 devem devolver "?".
#include <string>
#include "teste.hpp"

std::string classificar(int nota) {
    // TODO: use if / else if
    return "?";
}

int main() {
    CHECK_IGUAL(std::string("A"), classificar(95));
    CHECK_IGUAL(std::string("A"), classificar(90));
    CHECK_IGUAL(std::string("B"), classificar(89));
    CHECK_IGUAL(std::string("C"), classificar(70));
    CHECK_IGUAL(std::string("D"), classificar(60));
    CHECK_IGUAL(std::string("F"), classificar(59));
    CHECK_IGUAL(std::string("F"), classificar(0));
    CHECK_IGUAL(std::string("?"), classificar(-1));
    CHECK_IGUAL(std::string("?"), classificar(101));
    return teste::resumo("ex01 · conceito");
}
