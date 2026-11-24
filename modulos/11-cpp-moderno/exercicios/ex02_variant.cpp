// Exercício 02 — variant
//
// Descreva o valor guardado:
//   int         → "int: <valor>"
//   double      → "double: <valor>"
//   std::string → "texto: <valor>"
//
// Use std::visit com uma lambda genérica e if constexpr,
// ou std::holds_alternative.
#include <string>
#include <variant>
#include "teste.hpp"

std::string descrever(const std::variant<int, double, std::string>& valor) {
    // TODO
    return "";
}

int main() {
    CHECK_IGUAL(std::string("int: 42"), descrever(42));
    CHECK_IGUAL(std::string("double: 3.5"), descrever(3.5));
    CHECK_IGUAL(std::string("texto: oi"), descrever(std::string("oi")));
    CHECK_IGUAL(std::string("int: -1"), descrever(-1));
    return teste::resumo("ex02 · variant");
}
