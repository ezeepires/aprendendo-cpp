// AULA 08 — Lendo e escrevendo arquivos
//
// Compile: g++ -std=c++20 -Wall -Wextra aulas/08_arquivos.cpp -o programa
// Rode:    ./programa

#include <fstream>
#include <iostream>
#include <string>

int main() {
    const std::string caminho = "/tmp/cpp_aula_arquivo.txt";

    // ---- ESCREVER ----
    {
        std::ofstream saida(caminho);       // cria ou apaga o que existia
        if (!saida) {
            std::cout << "não consegui abrir para escrita\n";
            return 1;
        }

        saida << "Ana,1111\n";
        saida << "Bia,2222\n";
        saida << "Caio,3333\n";
    }   // <-- fim do bloco: aqui o arquivo fecha e o conteúdo é gravado

    std::cout << "arquivo escrito em " << caminho << "\n";

    // ---- LER ----
    std::ifstream entrada(caminho);
    if (!entrada) {
        std::cout << "não consegui abrir para leitura\n";
        return 1;
    }

    std::cout << "\nconteúdo:\n";
    std::string linha;
    int numero = 1;
    while (std::getline(entrada, linha)) {   // lê uma linha por vez
        std::cout << numero++ << ": " << linha << "\n";
    }

    return 0;
}
