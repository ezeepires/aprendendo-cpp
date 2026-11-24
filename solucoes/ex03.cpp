// SOLUÇÃO 03 — Conceito pela nota
#include <iostream>

int main() {
    int nota = 0;
    std::cout << "Nota: ";
    std::cin >> nota;

    if (nota < 0 || nota > 100) {
        std::cout << "Nota inválida\n";
    } else if (nota >= 90) {
        std::cout << "A\n";
    } else if (nota >= 80) {
        std::cout << "B\n";
    } else if (nota >= 70) {
        std::cout << "C\n";
    } else if (nota >= 60) {
        std::cout << "D\n";
    } else {
        std::cout << "F\n";
    }
    return 0;
}
