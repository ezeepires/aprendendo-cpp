// Exercício 01 — Divisão segura
//
// Se divisor == 0, lance std::invalid_argument("divisão por zero").
// Caso contrário, devolva a / b.
#include <stdexcept>
#include "teste.hpp"

int dividir(int a, int b) {
    // TODO
    return 0;
}

int main() {
    CHECK_IGUAL(5, dividir(10, 2));
    CHECK_IGUAL(0, dividir(1, 2));
    CHECK_IGUAL(-3, dividir(-9, 3));

    bool lancou = false;
    try {
        dividir(1, 0);
    } catch (const std::invalid_argument& e) {
        lancou = true;
        CHECK(std::string(e.what()).find("zero") != std::string::npos);
    }
    CHECK(lancou);

    // Também deve lançar para 0/0
    lancou = false;
    try {
        dividir(0, 0);
    } catch (const std::invalid_argument&) {
        lancou = true;
    }
    CHECK(lancou);
    return teste::resumo("ex01 · dividir");
}
