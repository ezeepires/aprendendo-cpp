// Exercício 01 — Saudação
//
// Implemente `saudacao` para devolver "Olá, <nome>!".
// Exemplo: saudacao("Ana") == "Olá, Ana!"
// Se o nome estiver vazio, devolva "Olá, pessoa desconhecida!"
#include <string>
#include "teste.hpp"

std::string saudacao(const std::string& nome) {
    // TODO: troque o return abaixo pela implementação correta.
    return "";
}

int main() {
    CHECK_IGUAL(std::string("Olá, Ana!"), saudacao("Ana"));
    CHECK_IGUAL(std::string("Olá, João Pedro!"), saudacao("João Pedro"));
    CHECK_IGUAL(std::string("Olá, pessoa desconhecida!"), saudacao(""));
    return teste::resumo("ex01 · saudação");
}
