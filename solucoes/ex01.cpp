// SOLUÇÃO 01 — Olá, usuário
#include <iostream>
#include <string>

int main() {
    std::string nome;
    int idade = 0;

    std::cout << "Digite seu nome: ";
    std::getline(std::cin, nome);

    std::cout << "Digite sua idade: ";
    std::cin >> idade;

    std::cout << "Olá, " << nome << "! Você tem " << idade << " anos.\n";
    return 0;
}
