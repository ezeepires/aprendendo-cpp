// Recursão: fatorial, Fibonacci e soma.
#include <iostream>

long long fatorial(int n) {
    if (n <= 1) return 1;          // caso base
    return n * fatorial(n - 1);
}

long long fibonacci(int n) {
    if (n <= 1) return static_cast<long long>(n);   // 0 ou 1
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int soma_ate(int n) {
    if (n == 0) return 0;
    return n + soma_ate(n - 1);
}

int main() {
    for (int i = 0; i <= 10; ++i) {
        std::cout << i << "! = " << fatorial(i) << "\n";
    }
    std::cout << "fib(10) = " << fibonacci(10) << "\n";
    std::cout << "soma até 100 = " << soma_ate(100) << "\n";
    return 0;
}
