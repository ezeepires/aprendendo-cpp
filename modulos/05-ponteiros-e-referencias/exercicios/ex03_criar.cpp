// Exercício 03 — Criar unique_ptr
//
// Devolva um std::unique_ptr<int> contendo `valor`.
// Use std::make_unique.
#include <memory>
#include "teste.hpp"

std::unique_ptr<int> criar(int valor) {
    // TODO
    return nullptr;
}

int main() {
    auto a = criar(42);
    CHECK(a != nullptr);
    if (a) CHECK_IGUAL(42, *a);

    auto b = criar(-7);
    CHECK(b != nullptr);
    if (b) CHECK_IGUAL(-7, *b);

    // O unique_ptr se encarrega de liberar: nenhum delete aqui.
    return teste::resumo("ex03 · unique_ptr");
}
