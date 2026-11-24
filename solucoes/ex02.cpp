// SOLUÇÃO 02 — Calculadora
#include <iostream>

int main() {
    int a = 0, b = 0;

    std::cout << "Primeiro número: ";
    std::cin >> a;
    std::cout << "Segundo número: ";
    std::cin >> b;

    std::cout << "Soma: " << a + b << "\n";
    std::cout << "Subtração: " << a - b << "\n";
    std::cout << "Multiplicação: " << a * b << "\n";

    if (b == 0) {
        std::cout << "Divisão: não dá para dividir por zero\n";
        return 0;
    }

    std::cout << "Divisão: " << a / b << "\n";
    std::cout << "Resto: " << a % b << "\n";
    std::cout << "Divisão real: " << static_cast<double>(a) / b << "\n";
    return 0;
}
