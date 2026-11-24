// Exercício 03 — Inverter string
//
// Devolva o texto ao contrário.
// "abc" → "cba" | "" → "" | "ovo" → "ovo"
//
// Tente fazer com laço (de trás para frente) e, depois, com std::reverse.
#include <string>
#include "teste.hpp"

std::string inverter(const std::string& texto) {
    // TODO
    return "";
}

int main() {
    CHECK_IGUAL(std::string("cba"), inverter("abc"));
    CHECK_IGUAL(std::string(""), inverter(""));
    CHECK_IGUAL(std::string("ovo"), inverter("ovo"));
    CHECK_IGUAL(std::string("odnum aloH"), inverter("Hola mundo"));
    CHECK_IGUAL(std::string("1"), inverter("1"));
    return teste::resumo("ex03 · inverter");
}
