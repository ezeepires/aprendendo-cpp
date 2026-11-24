// std::vector na prática.
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numeros = {4, 8, 15, 16, 23, 42};

    std::cout << "elementos: " << numeros.size() << "\n";
    std::cout << "primeiro:  " << numeros.front() << "\n";
    std::cout << "último:    " << numeros.back() << "\n";

    numeros.push_back(99);
    std::cout << "depois do push_back: " << numeros.size() << "\n";

    std::cout << "conteúdo: ";
    for (const auto& n : numeros) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    // Alterando pela referência
    for (int& n : numeros) {
        n *= 2;
    }
    std::cout << "dobrado: ";
    for (int n : numeros) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    numeros.pop_back();
    std::cout << "sem o último: " << numeros.size() << " elementos\n";
    return 0;
}
