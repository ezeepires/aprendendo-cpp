// AULA 01 — Primeiro programa
//
// Compile:  g++ -std=c++20 -Wall -Wextra aulas/01_primeiro_programa.cpp -o programa
// Rode:     ./programa

#include <iostream>   // traz std::cout (saída) e std::cin (entrada)

int main() {
    std::cout << "Olá, mundo!\n";
    std::cout << "Estou aprendendo C++ no Ubuntu.\n";

    // Toda instrução termina com ponto e vírgula.
    // "\n" quebra a linha. Existe também std::endl, que quebra e força
    // a saída na tela na hora (um pouco mais lento).
    std::cout << "Uma linha" << std::endl;
    std::cout << "Outra linha" << '\n';

    return 0;   // 0 significa: terminou sem erro
}
