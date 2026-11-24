// Exercício 02 — Contar palavras
//
// Receba um texto e devolva um map com quantas vezes cada palavra aparece.
// Considere que as palavras já vêm separadas por espaço (não precisa pontuação).
// Exemplo: "a b a" → {"a": 2, "b": 1}
#include <map>
#include <sstream>
#include <string>
#include "teste.hpp"

std::map<std::string, int> contar_palavras(const std::string& texto) {
    // TODO: std::istringstream + operador >> e ++contagem[palavra]
    return {};
}

int main() {
    auto r1 = contar_palavras("a b a");
    CHECK_IGUAL(std::size_t(2), r1.size());
    CHECK_IGUAL(2, r1["a"]);
    CHECK_IGUAL(1, r1["b"]);

    auto r2 = contar_palavras("cpp cpp cpp");
    CHECK_IGUAL(std::size_t(1), r2.size());
    CHECK_IGUAL(3, r2["cpp"]);

    auto r3 = contar_palavras("");
    CHECK(r3.empty());

    auto r4 = contar_palavras("x y z x y x");
    CHECK_IGUAL(3, r4["x"]);
    CHECK_IGUAL(2, r4["y"]);
    CHECK_IGUAL(1, r4["z"]);
    return teste::resumo("ex02 · contar palavras");
}
