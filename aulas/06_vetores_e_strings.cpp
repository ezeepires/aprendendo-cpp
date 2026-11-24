// AULA 06 — Vetores (std::vector) e textos (std::string)
//
// Compile: g++ -std=c++20 -Wall -Wextra aulas/06_vetores_e_strings.cpp -o programa
// Rode:    ./programa

#include <algorithm>   // sort
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Um vetor guarda vários valores do mesmo tipo e pode crescer
    std::vector<int> notas = {8, 5, 10, 7};

    std::cout << "quantidade: " << notas.size() << "\n";
    std::cout << "primeira:   " << notas.front() << "\n";
    std::cout << "última:     " << notas.back() << "\n";

    notas.push_back(9);            // adiciona no fim
    std::cout << "depois do push_back: " << notas.size() << "\n";

    // Percorrendo
    std::cout << "notas: ";
    for (int nota : notas) {       // "para cada nota em notas"
        std::cout << nota << " ";
    }
    std::cout << "\n";

    // Acesso pela posição (começa em 0)
    std::cout << "notas[0] = " << notas[0] << "\n";
    std::cout << "notas[1] = " << notas[1] << "\n";

    // Somando e tirando a média
    int total = 0;
    for (int nota : notas) {
        total += nota;
    }
    std::cout << "soma = " << total << "\n";
    std::cout << "média = " << static_cast<double>(total) / notas.size() << "\n";

    // Ordenar
    std::sort(notas.begin(), notas.end());
    std::cout << "ordenado: ";
    for (int nota : notas) std::cout << nota << " ";
    std::cout << "\n";

    // Strings
    std::string nome = "Ana";
    std::string sobrenome = "Silva";
    std::string completo = nome + " " + sobrenome;

    std::cout << "\nnome completo: " << completo << "\n";
    std::cout << "tem " << completo.size() << " letras\n";
    std::cout << "primeira letra: " << completo[0] << "\n";

    if (completo.find("Silva") != std::string::npos) {
        std::cout << "achei 'Silva'\n";
    }

    // Contando vogais
    int vogais = 0;
    for (char c : completo) {
        if (std::string("aeiouAEIOU").find(c) != std::string::npos) ++vogais;
    }
    std::cout << "vogais: " << vogais << "\n";

    return 0;
}
