// Lendo linhas, palavras e números.
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    const std::string caminho = "/tmp/aprendendo_cpp_exemplo.txt";

    std::ifstream in(caminho);
    if (!in) {
        std::cout << "rode 01_escrever antes, ou crie " << caminho << "\n";
        return 1;
    }

    std::cout << "--- linha por linha ---\n";
    std::string linha;
    while (std::getline(in, linha)) {
        std::cout << linha << "\n";
    }

    in.clear();
    in.seekg(0);

    std::cout << "--- palavra por palavra (contagem) ---\n";
    int palavras = 0;
    std::string palavra;
    while (in >> palavra) ++palavras;
    std::cout << palavras << " palavras\n";

    return 0;
}
