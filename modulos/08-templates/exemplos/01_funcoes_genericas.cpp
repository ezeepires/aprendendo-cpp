// Funções template.
#include <iostream>
#include <string>
#include <vector>

template <typename T>
T maior(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
void imprimir(const std::vector<T>& v) {
    std::cout << "[";
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ", ";
    }
    std::cout << "]\n";
}

template <typename T>
T soma(const std::vector<T>& v) {
    T total{};
    for (const auto& x : v) total += x;
    return total;
}

int main() {
    std::cout << maior(3, 7) << "\n";
    std::cout << maior(2.5, 1.5) << "\n";
    std::cout << maior(std::string("ana"), std::string("bia")) << "\n";

    imprimir(std::vector<int>{1, 2, 3});
    imprimir(std::vector<std::string>{"a", "b"});
    imprimir(std::vector<double>{1.5, 2.5});

    std::cout << "soma int: " << soma(std::vector<int>{1, 2, 3}) << "\n";
    std::cout << "soma double: " << soma(std::vector<double>{1.5, 2.5}) << "\n";
    return 0;
}
