// Vetor + algoritmos da biblioteca padrão.
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
    std::vector<int> v = {5, 3, 9, 1, 7};

    std::sort(v.begin(), v.end());
    std::cout << "ordenado: ";
    for (int n : v) std::cout << n << " ";
    std::cout << "\n";

    std::cout << "soma: " << std::accumulate(v.begin(), v.end(), 0) << "\n";
    std::cout << "maior: " << *std::max_element(v.begin(), v.end()) << "\n";
    std::cout << "menor: " << *std::min_element(v.begin(), v.end()) << "\n";

    auto it = std::find(v.begin(), v.end(), 7);
    if (it != v.end()) {
        std::cout << "7 está na posição " << std::distance(v.begin(), it) << "\n";
    }

    std::string palavra = "programar";
    std::reverse(palavra.begin(), palavra.end());
    std::cout << "invertida: " << palavra << "\n";

    std::cout << "ocorrências de 'r': "
              << std::count(palavra.begin(), palavra.end(), 'r') << "\n";
    return 0;
}
