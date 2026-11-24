// AULA 04 — Repetindo: for, while, do-while
//
// Compile: g++ -std=c++20 -Wall -Wextra aulas/04_repeticoes.cpp -o programa
// Rode:    ./programa

#include <iostream>

int main() {
    // for: quando você sabe quantas vezes vai repetir
    std::cout << "Contando de 1 a 5: ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    // while: quando não sabe quantas vezes
    std::cout << "Contagem regressiva: ";
    int n = 5;
    while (n > 0) {
        std::cout << n << " ";
        --n;
    }
    std::cout << "\n";

    // do-while: executa pelo menos uma vez
    int tentativas = 0;
    do {
        ++tentativas;
    } while (tentativas < 3);
    std::cout << "O do-while rodou " << tentativas << " vezes\n";

    // Soma de 1 até 100
    int soma = 0;
    for (int i = 1; i <= 100; ++i) {
        soma += i;
    }
    std::cout << "1 + 2 + ... + 100 = " << soma << "\n";

    // break sai do laço; continue pula para o próximo
    std::cout << "Ímpares até 9: ";
    for (int i = 1; i <= 10; ++i) {
        if (i % 2 == 0) continue;   // pula os pares
        if (i > 9) break;           // para no 10
        std::cout << i << " ";
    }
    std::cout << "\n";

    // Laço dentro de laço: um triângulo de asteriscos
    for (int linha = 1; linha <= 5; ++linha) {
        for (int coluna = 1; coluna <= linha; ++coluna) {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}
