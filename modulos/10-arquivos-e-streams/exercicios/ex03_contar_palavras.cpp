// Exercício 03 — Contar palavras de um arquivo
//
// Conte palavras separadas por espaço/quebra de linha.
// Arquivo inexistente → 0.
// Dica: std::ifstream + while (in >> palavra).
#include <fstream>
#include <string>
#include <filesystem>
#include "teste.hpp"

int contar_palavras(const std::string& caminho) {
    // TODO
    return 0;
}

int main() {
    const std::string caminho =
        (std::filesystem::temp_directory_path() / "aprendendo_cpp_ex03.txt").string();

    {
        std::ofstream out(caminho);
        out << "uma duas tres\nquatro cinco\n";
    }
    CHECK_IGUAL(5, contar_palavras(caminho));

    {
        std::ofstream out(caminho);      // arquivo vazio
    }
    CHECK_IGUAL(0, contar_palavras(caminho));

    CHECK_IGUAL(0, contar_palavras("/arquivo/inexistente.txt"));

    std::filesystem::remove(caminho);
    return teste::resumo("ex03 · contar palavras");
}
