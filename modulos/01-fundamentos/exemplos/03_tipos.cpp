// Tipos, conversões e limites.
#include <iostream>
#include <limits>
#include <string>

int main() {
    int inteiro = 42;
    double real = 3.75;
    char letra = 'C';
    bool verdadeiro = true;
    std::string texto = "C++";
    auto deduzido = 7LL;  // long long

    std::cout << "inteiro: " << inteiro << "\n";
    std::cout << "real:    " << real << "\n";
    std::cout << "letra:   " << letra << "\n";
    std::cout << "bool:    " << verdadeiro << " (1 = true)\n";
    std::cout << "texto:   " << texto << "\n";
    std::cout << "auto:    " << deduzido << "\n";

    // Divisão inteira x divisão real
    std::cout << "\n5 / 2     = " << 5 / 2 << "\n";
    std::cout << "5.0 / 2   = " << 5.0 / 2 << "\n";

    // Conversão explícita
    std::cout << "3.9 -> int = " << static_cast<int>(3.9) << "\n";

    // Limites do int
    std::cout << "\nmaior int: " << std::numeric_limits<int>::max() << "\n";
    std::cout << "menor int: " << std::numeric_limits<int>::min() << "\n";

    return 0;
}
