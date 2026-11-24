// Exercício 04 — Contar vogais
//
// Conte a, e, i, o, u — maiúsculas e minúsculas contam.
// "Programar" → 3 (o, a, a)
// Dica: use find em "aeiouAEIOU" para não escrever 10 ifs.
#include <string>
#include "teste.hpp"

int contar_vogais(const std::string& texto) {
    // TODO
    return 0;
}

int main() {
    CHECK_IGUAL(3, contar_vogais("Programar"));
    CHECK_IGUAL(5, contar_vogais("aeiou"));
    CHECK_IGUAL(5, contar_vogais("AEIOU"));
    CHECK_IGUAL(0, contar_vogais("xyz"));
    CHECK_IGUAL(0, contar_vogais(""));
    CHECK_IGUAL(4, contar_vogais("C++ e otimo"));  // e, o, i, o
    return teste::resumo("ex04 · vogais");
}
