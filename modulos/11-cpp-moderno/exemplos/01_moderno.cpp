// auto, structured bindings, optional e variant.
#include <iostream>
#include <map>
#include <optional>
#include <string>
#include <variant>
#include <vector>

std::optional<int> para_inteiro(const std::string& texto) {
    try {
        std::size_t pos = 0;
        int valor = std::stoi(texto, &pos);
        if (pos != texto.size()) return std::nullopt;
        return valor;
    } catch (...) {
        return std::nullopt;
    }
}

int main() {
    std::map<std::string, int> idade{{"Ana", 30}, {"Bia", 25}};
    for (const auto& [nome, anos] : idade) {
        std::cout << nome << " tem " << anos << "\n";
    }

    std::cout << "42  -> " << para_inteiro("42").value_or(-1) << "\n";
    std::cout << "abc -> " << para_inteiro("abc").value_or(-1) << "\n";

    std::variant<int, double, std::string> valor = 3.5;
    std::visit([](const auto& v) {
        std::cout << "variant: " << v << "\n";
    }, valor);

    valor = std::string("agora sou texto");
    std::visit([](const auto& v) {
        std::cout << "variant: " << v << "\n";
    }, valor);

    auto* d = std::get_if<double>(&valor);
    std::cout << "tem double? " << (d != nullptr) << "\n";
    return 0;
}
