// SOLUÇÃO 04 — Tabuada
#include <iostream>

int main() {
    int n = 0;
    std::cout << "Número: ";
    std::cin >> n;

    std::cout << "Tabuada do " << n << ":\n";
    for (int i = 1; i <= 10; ++i) {
        std::cout << n << " x " << i << " = " << n * i << "\n";
    }
    return 0;
}
