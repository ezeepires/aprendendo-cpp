// Exercício 01 — Salvar linhas
//
// Grave cada string do vetor em uma linha do arquivo (uma por linha, '\n' no fim).
// Devolva true se conseguiu abrir/escrever, false caso contrário.
// Arquivo inexistente no diretório informado → false (sem lançar exceção).
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include "teste.hpp"

bool salvar_linhas(const std::string& caminho, const std::vector<std::string>& linhas) {
    // TODO
    return false;
}

int main() {
    const std::string caminho =
        (std::filesystem::temp_directory_path() / "aprendendo_cpp_ex01.txt").string();

    CHECK(salvar_linhas(caminho, {"primeira", "segunda", "terceira"}));

    std::ifstream in(caminho);
    std::string l1, l2, l3, extra;
    CHECK(std::getline(in, l1));
    CHECK(std::getline(in, l2));
    CHECK(std::getline(in, l3));
    CHECK_IGUAL(std::string("primeira"), l1);
    CHECK_IGUAL(std::string("segunda"), l2);
    CHECK_IGUAL(std::string("terceira"), l3);
    CHECK(!std::getline(in, extra));      // nada além das 3 linhas

    CHECK(salvar_linhas(caminho, {}));    // vetor vazio: arquivo vazio é válido

    CHECK(!salvar_linhas("/caminho/que/nao/existe/arquivo.txt", {"x"}));

    std::filesystem::remove(caminho);
    return teste::resumo("ex01 · salvar linhas");
}
