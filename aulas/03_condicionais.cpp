// AULA 03 — Tomando decisões: if, else, switch
//
// Compile: g++ -std=c++20 -Wall -Wextra aulas/03_condicionais.cpp -o programa
// Rode:    ./programa

#include <iostream>

int main() {
    int nota = 75;

    // O primeiro if verdadeiro ganha; o resto é ignorado.
    if (nota >= 90) {
        std::cout << "Conceito A\n";
    } else if (nota >= 80) {
        std::cout << "Conceito B\n";
    } else if (nota >= 70) {
        std::cout << "Conceito C\n";
    } else {
        std::cout << "Precisa melhorar\n";
    }

    // Comparações devolvem verdadeiro/falso
    int idade = 17;
    bool autorizacao = true;

    // && = e   |   || = ou   |   ! = não
    if (idade >= 18 || autorizacao) {
        std::cout << "Pode entrar.\n";
    }

    if (idade < 18 && !autorizacao) {
        std::cout << "Não pode entrar.\n";
    }

    // Operador ternário: condição ? se_verdadeiro : se_falso
    std::cout << "Situação: " << (idade >= 18 ? "adulto" : "menor") << "\n";

    // switch: bom para comparar um valor com várias opções
    int opcao = 2;
    switch (opcao) {
        case 1:
            std::cout << "Você escolheu somar.\n";
            break;                  // sem break, cai no próximo case
        case 2:
            std::cout << "Você escolheu subtrair.\n";
            break;
        default:
            std::cout << "Opção desconhecida.\n";
            break;
    }

    return 0;
}
