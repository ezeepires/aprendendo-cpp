// Exercício 02 — Conversão de temperatura
//
// Fórmula: F = C * 9 / 5 + 32
// Implemente `para_fahrenheit` e `para_celsius`.
#include "teste.hpp"

double para_fahrenheit(double celsius) {
    // TODO
    return 0.0;
}

double para_celsius(double fahrenheit) {
    // TODO: F = C * 9 / 5 + 32  →  C = (F - 32) * 5 / 9
    return 0.0;
}

int main() {
    CHECK_PROXIMO(32.0, para_fahrenheit(0.0), 0.001);
    CHECK_PROXIMO(212.0, para_fahrenheit(100.0), 0.001);
    CHECK_PROXIMO(-40.0, para_fahrenheit(-40.0), 0.001);
    CHECK_PROXIMO(0.0, para_celsius(32.0), 0.001);
    CHECK_PROXIMO(100.0, para_celsius(212.0), 0.001);
    return teste::resumo("ex02 · temperatura");
}
