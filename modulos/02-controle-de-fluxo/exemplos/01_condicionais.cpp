// Condicionais e operadores lógicos.
#include <iostream>

int main() {
    int idade = 0;
    bool tem_autorizacao = false;

    std::cout << "Idade: ";
    std::cin >> idade;

    if (idade < 0) {
        std::cout << "Idade inválida.\n";
    } else if (idade < 16) {
        std::cout << "Não pode votar.\n";
    } else if (idade < 18 || idade >= 70) {
        std::cout << "Voto facultativo.\n";
    } else {
        std::cout << "Voto obrigatório.\n";
    }

    std::cout << "Tem autorização dos responsáveis? (1 = sim, 0 = não): ";
    std::cin >> tem_autorizacao;

    if (idade < 18 && tem_autorizacao) {
        std::cout << "Pode entrar acompanhado de autorização.\n";
    }

    // Operador ternário: condição ? se_verdadeiro : se_falso
    std::cout << "Situação: " << (idade >= 18 ? "adulto" : "menor") << "\n";
    return 0;
}
