// switch com menu simples.
#include <iostream>

int main() {
    std::cout << "1 - somar\n2 - subtrair\n0 - sair\n";
    std::cout << "Escolha: ";

    int opcao = 0;
    std::cin >> opcao;

    switch (opcao) {
        case 1: {
            double a = 0, b = 0;
            std::cout << "Dois números: ";
            std::cin >> a >> b;
            std::cout << "Soma = " << a + b << "\n";
            break;
        }
        case 2: {
            double a = 0, b = 0;
            std::cout << "Dois números: ";
            std::cin >> a >> b;
            std::cout << "Diferença = " << a - b << "\n";
            break;
        }
        case 0:
            std::cout << "Até logo!\n";
            break;
        default:
            std::cout << "Opção inválida.\n";
            break;
    }
    return 0;
}
