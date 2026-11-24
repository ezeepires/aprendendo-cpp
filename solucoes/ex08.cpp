// SOLUÇÃO 08 — Arquivo
#include <fstream>
#include <iostream>
#include <string>

int main() {
    const std::string caminho = "/tmp/nomes.txt";

    // Escrever — o bloco { } garante que o arquivo fecha (e grava)
    // antes de tentarmos ler.
    {
        std::ofstream saida(caminho);
        if (!saida) {
            std::cout << "erro ao abrir para escrita\n";
            return 1;
        }

        for (int i = 1; i <= 3; ++i) {
            std::string nome;
            std::cout << "Nome " << i << ": ";
            std::getline(std::cin, nome);
            saida << nome << '\n';
        }
    }

    // Ler
    std::ifstream entrada(caminho);
    if (!entrada) {
        std::cout << "erro ao abrir para leitura\n";
        return 1;
    }

    std::string linha;
    int numero = 1;
    while (std::getline(entrada, linha)) {
        std::cout << numero++ << ": " << linha << "\n";
    }
    return 0;
}
