// Classe template: uma pilha genérica.
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class Pilha {
public:
    void push(const T& valor) { dados_.push_back(valor); }

    T pop() {
        if (dados_.empty()) {
            throw std::underflow_error("pilha vazia");
        }
        T valor = dados_.back();
        dados_.pop_back();
        return valor;
    }

    const T& topo() const {
        if (dados_.empty()) throw std::underflow_error("pilha vazia");
        return dados_.back();
    }

    bool vazia() const { return dados_.empty(); }
    std::size_t tamanho() const { return dados_.size(); }

private:
    std::vector<T> dados_;
};

int main() {
    Pilha<int> numeros;
    numeros.push(1);
    numeros.push(2);
    numeros.push(3);
    std::cout << "topo: " << numeros.topo() << " (tamanho " << numeros.tamanho() << ")\n";
    std::cout << "pop: " << numeros.pop() << "\n";
    std::cout << "topo agora: " << numeros.topo() << "\n";

    Pilha<std::string> palavras;
    palavras.push("olá");
    palavras.push("mundo");
    std::cout << palavras.pop() << " " << palavras.pop() << "\n";

    try {
        palavras.pop();
    } catch (const std::exception& e) {
        std::cout << "erro esperado: " << e.what() << "\n";
    }
    return 0;
}
