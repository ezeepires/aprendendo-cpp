// Entrada e saída de dados.
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    std::string nome;
    int idade = 0;
    double altura = 0.0;

    std::cout << "Seu nome: ";
    std::getline(std::cin, nome);

    std::cout << "Sua idade: ";
    std::cin >> idade;

    std::cout << "Sua altura (m): ";
    std::cin >> altura;

    std::cout << "\n----- Ficha -----\n";
    std::cout << "Nome:  " << nome << "\n";
    std::cout << "Idade: " << idade << " anos\n";
    std::cout << "Altura: " << std::fixed << std::setprecision(2) << altura << " m\n";
    // A idade em 2030: some 4 anos (exemplo de expressão aritmética)
    std::cout << "Em 2030 você terá " << idade + 4 << " anos.\n";

    return 0;
}
