// Containers: vector, map, set.
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
    // map: contagem de palavras
    std::vector<std::string> palavras = {"c++", "é", "c++", "rápido", "é", "c++"};
    std::map<std::string, int> contagem;
    for (const auto& p : palavras) {
        ++contagem[p];
    }
    for (const auto& [palavra, vezes] : contagem) {
        std::cout << palavra << ": " << vezes << "\n";
    }

    // set: valores únicos e ordenados
    std::set<int> unicos = {3, 1, 3, 2, 1};
    std::cout << "únicos: ";
    for (int n : unicos) std::cout << n << " ";
    std::cout << "\n";

    // vector como pilha
    std::vector<int> pilha;
    pilha.push_back(1);
    pilha.push_back(2);
    std::cout << "topo: " << pilha.back() << "\n";
    pilha.pop_back();
    std::cout << "novo topo: " << pilha.back() << "\n";
    return 0;
}
