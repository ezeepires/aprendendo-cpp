// for, while, do-while e laços aninhados.
#include <iostream>

int main() {
    std::cout << "for: ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "while (contagem regressiva): ";
    int n = 5;
    while (n > 0) {
        std::cout << n << " ";
        --n;
    }
    std::cout << "\n";

    int tentativas = 0;
    do {
        ++tentativas;
    } while (tentativas < 3);
    std::cout << "do-while executou " << tentativas << " vezes\n";

    std::cout << "\ntabuada do 7:\n";
    for (int i = 1; i <= 10; ++i) {
        std::cout << "7 x " << i << " = " << 7 * i << "\n";
    }

    std::cout << "\ntriângulo:\n";
    for (int linha = 1; linha <= 5; ++linha) {
        for (int coluna = 0; coluna < linha; ++coluna) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
    return 0;
}
