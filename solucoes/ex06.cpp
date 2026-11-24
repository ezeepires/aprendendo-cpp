// SOLUÇÃO 06 — Média, maior e menor
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numeros;

    for (int i = 1; i <= 5; ++i) {
        int valor = 0;
        std::cout << "Número " << i << ": ";
        std::cin >> valor;
        numeros.push_back(valor);
    }

    int menor = numeros[0];
    int maior = numeros[0];
    int soma = 0;

    for (int n : numeros) {
        if (n < menor) menor = n;
        if (n > maior) maior = n;
        soma += n;
    }

    std::cout << "Menor: " << menor << "\n";
    std::cout << "Maior: " << maior << "\n";
    std::cout << "Média: " << static_cast<double>(soma) / numeros.size() << "\n";
    return 0;
}
