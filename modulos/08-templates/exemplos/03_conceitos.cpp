// Conceitos (C++20).
#include <concepts>
#include <iostream>
#include <string>

template <typename T>
concept Numerico = std::integral<T> || std::floating_point<T>;

template <Numerico T>
T metade(T valor) {
    return valor / 2;
}

// Requer que T tenha .size()
template <typename T>
concept TemTamanho = requires(T t) { t.size(); };

template <TemTamanho T>
void mostrar_tamanho(const T& valor) {
    std::cout << "tamanho: " << valor.size() << "\n";
}

int main() {
    std::cout << metade(10) << "\n";
    std::cout << metade(9.0) << "\n";
    // metade(std::string("x"));   // erro de compilação: string não é numérica

    mostrar_tamanho(std::string("abc"));
    return 0;
}
