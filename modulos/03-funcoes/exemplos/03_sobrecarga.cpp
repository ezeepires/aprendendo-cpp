// Sobrecarga e valores padrão.
#include <iostream>
#include <string>

int soma(int a, int b) {
    return a + b;
}

int soma(int a, int b, int c) {
    return a + b + c;
}

double soma(double a, double b) {
    return a + b;
}

std::string repetir(const std::string& texto, int vezes = 3) {
    std::string resultado;
    for (int i = 0; i < vezes; ++i) {
        resultado += texto;
    }
    return resultado;
}

int main() {
    std::cout << soma(2, 3) << "\n";          // int, int
    std::cout << soma(2, 3, 4) << "\n";       // int, int, int
    std::cout << soma(1.5, 2.5) << "\n";      // double, double
    std::cout << repetir("ab") << "\n";       // usa 3
    std::cout << repetir("ab", 5) << "\n";
    return 0;
}
