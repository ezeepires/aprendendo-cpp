// SOLUÇÃO 05 — Fatorial
#include <iostream>

long long fatorial(int n) {
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

int main() {
    int n = 0;
    std::cout << "Digite um número: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "número inválido\n";
        return 0;
    }

    std::cout << n << "! = " << fatorial(n) << "\n";
    return 0;
}
