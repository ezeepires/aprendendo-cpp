// Exercício 04 — Área do círculo
//
// Área = π * r². Use std::numbers::pi (precisa de <numbers> e C++20).
// Implemente também `circunferencia`: C = 2 * π * r.
#include <numbers>
#include "teste.hpp"

double area_circulo(double raio) {
    // TODO
    return 0.0;
}

double circunferencia(double raio) {
    // TODO
    return 0.0;
}

int main() {
    CHECK_PROXIMO(std::numbers::pi, area_circulo(1.0), 0.0001);
    CHECK_PROXIMO(4.0 * std::numbers::pi, area_circulo(2.0), 0.0001);
    CHECK_PROXIMO(0.0, area_circulo(0.0), 0.0001);
    CHECK_PROXIMO(2.0 * std::numbers::pi, circunferencia(1.0), 0.0001);
    CHECK_PROXIMO(10.0 * std::numbers::pi, circunferencia(5.0), 0.0001);
    return teste::resumo("ex04 · círculo");
}
