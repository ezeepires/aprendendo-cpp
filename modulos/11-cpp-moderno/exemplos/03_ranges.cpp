// C++20 ranges: pipelines.
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto resultado = numeros
                   | std::views::filter([](int n) { return n % 2 == 0; })
                   | std::views::transform([](int n) { return n * n; })
                   | std::views::take(3);

    std::cout << "3 primeiros quadrados de pares: ";
    for (int n : resultado) {
        std::cout << n << " ";     // 4 16 36
    }
    std::cout << "\n";

    std::cout << "pares: ";
    for (int n : numeros | std::views::filter([](int x) { return x % 2 == 0; })) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    return 0;
}
