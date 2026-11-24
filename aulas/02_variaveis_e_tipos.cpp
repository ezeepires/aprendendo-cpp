// AULA 02 — Variáveis, tipos e entrada de dados
//
// Compile: g++ -std=c++20 -Wall -Wextra aulas/02_variaveis_e_tipos.cpp -o programa
// Rode:    ./programa

#include <iostream>
#include <string>

int main() {
    // Os tipos mais usados
    int idade = 25;             // número inteiro
    double altura = 1.75;       // número com casas decimais
    char inicial = 'A';         // um único caractere (aspas simples)
    bool estudando = true;      // verdadeiro ou falso
    std::string nome = "Ana";   // texto (aspas duplas)

    std::cout << "Nome: " << nome << "\n";
    std::cout << "Inicial: " << inicial << "\n";
    std::cout << "Idade: " << idade << " anos\n";
    std::cout << "Altura: " << altura << " m\n";
    std::cout << "Estudando? " << estudando << "  (1 = sim, 0 = não)\n";

    // const = valor que nunca muda
    const int ANO_ATUAL = 2026;
    std::cout << "Ano de nascimento aproximado: " << ANO_ATUAL - idade << "\n";

    // Divisão de inteiros descarta a parte decimal!
    std::cout << "\n10 / 3   = " << 10 / 3 << "\n";
    std::cout << "10.0 / 3 = " << 10.0 / 3 << "\n";

    // Convertendo de propósito
    int a = 10, b = 3;
    double media = static_cast<double>(a) / b;
    std::cout << "média = " << media << "\n";

    // Lendo dados do teclado
    std::cout << "\nDigite seu nome: ";
    std::string quem;
    std::getline(std::cin, quem);   // lê a linha inteira, com espaços

    std::cout << "Digite sua idade: ";
    int anos = 0;
    std::cin >> anos;

    std::cout << "Prazer, " << quem << "! Você tem " << anos << " anos.\n";
    std::cout << "Em 2030 você terá " << anos + 4 << ".\n";

    return 0;
}
