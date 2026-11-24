// Exercício 02 — Ler linhas
//
// Devolva todas as linhas do arquivo, sem o '\n'.
// Se não conseguir abrir, devolva um vetor vazio.
// Linhas vazias no meio do arquivo devem ser preservadas.
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include "teste.hpp"

std::vector<std::string> ler_linhas(const std::string& caminho) {
    // TODO
    return {};
}

int main() {
    const std::string caminho =
        (std::filesystem::temp_directory_path() / "aprendendo_cpp_ex02.txt").string();

    {
        std::ofstream out(caminho);
        out << "alfa\nbeta\n\ngama\n";
    }

    const auto linhas = ler_linhas(caminho);
    CHECK_IGUAL(std::size_t(4), linhas.size());
    if (linhas.size() == 4) {
        CHECK_IGUAL(std::string("alfa"), linhas[0]);
        CHECK_IGUAL(std::string("beta"), linhas[1]);
        CHECK_IGUAL(std::string(""), linhas[2]);
        CHECK_IGUAL(std::string("gama"), linhas[3]);
    }

    CHECK(ler_linhas("/nao/existe.txt").empty());

    std::filesystem::remove(caminho);
    return teste::resumo("ex02 · ler linhas");
}
