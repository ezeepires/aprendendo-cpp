// AULA 05 — Funções e recursão
//
// Compile: g++ -std=c++20 -Wall -Wextra aulas/05_funcoes.cpp -o programa
// Rode:    ./programa

#include <iostream>

// Função simples: recebe dois números e devolve a soma
int soma(int a, int b) {
    return a + b;
}

// void = não devolve nada
void linha() {
    std::cout << "----------\n";
}

// Guarda o resultado em "resultado" (passagem por referência, o &)
void dividir(int a, int b, int& quociente, int& resto) {
    quociente = a / b;
    resto = a % b;
}

// Valor padrão: se não passar o expoente, usa 2
int potencia(int base, int expoente = 2) {
    int r = 1;
    for (int i = 0; i < expoente; ++i) {
        r *= base;
    }
    return r;
}

// Função que chama a si mesma (recursão)
// Precisa sempre de um caso que pare, senão trava o programa.
long long fatorial(int n) {
    if (n <= 1) return 1;            // caso base
    return n * fatorial(n - 1);      // caso recursivo
}

int main() {
    linha();
    std::cout << "soma(2, 3) = " << soma(2, 3) << "\n";

    int q = 0, r = 0;
    dividir(17, 5, q, r);
    std::cout << "17 / 5 = " << q << " e sobra " << r << "\n";

    std::cout << "5 ao quadrado = " << potencia(5) << "\n";
    std::cout << "2 na 10      = " << potencia(2, 10) << "\n";

    std::cout << "5! = " << fatorial(5) << "\n";
    std::cout << "10! = " << fatorial(10) << "\n";
    linha();

    return 0;
}
