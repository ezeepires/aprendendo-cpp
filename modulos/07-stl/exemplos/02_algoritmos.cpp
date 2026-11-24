// Algoritmos e lambdas.
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
    std::vector<int> v = {5, -3, 9, 0, -1, 7, 2};

    std::sort(v.begin(), v.end());
    std::cout << "crescente: ";
    for (int n : v) std::cout << n << " ";
    std::cout << "\n";

    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    std::cout << "decrescente: ";
    for (int n : v) std::cout << n << " ";
    std::cout << "\n";

    const int negativos = static_cast<int>(
        std::count_if(v.begin(), v.end(), [](int n) { return n < 0; }));
    std::cout << "negativos: " << negativos << "\n";

    std::cout << "soma: " << std::accumulate(v.begin(), v.end(), 0) << "\n";

    // Filtrar mantendo só positivos
    std::vector<int> positivos;
    std::copy_if(v.begin(), v.end(), std::back_inserter(positivos),
                 [](int n) { return n > 0; });
    std::cout << "positivos: ";
    for (int n : positivos) std::cout << n << " ";
    std::cout << "\n";

    // Remover pares do próprio vetor (erase-remove)
    v.erase(std::remove_if(v.begin(), v.end(), [](int n) { return n % 2 == 0; }),
            v.end());
    std::cout << "sem pares: ";
    for (int n : v) std::cout << n << " ";
    std::cout << "\n";

    // Transformar cada elemento
    std::vector<int> quadrados;
    std::transform(positivos.begin(), positivos.end(),
                   std::back_inserter(quadrados), [](int n) { return n * n; });
    std::cout << "quadrados: ";
    for (int n : quadrados) std::cout << n << " ";
    std::cout << "\n";
    return 0;
}
