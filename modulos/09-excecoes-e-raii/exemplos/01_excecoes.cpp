// try / catch / throw com exceções padrão e personalizada.
#include <iostream>
#include <stdexcept>
#include <string>

class ErroSaldo : public std::runtime_error {
public:
    ErroSaldo(double faltando)
        : std::runtime_error("saldo insuficiente"), faltando_(faltando) {}

    double faltando() const { return faltando_; }

private:
    double faltando_;
};

void sacar(double saldo, double valor) {
    if (valor <= 0) throw std::invalid_argument("valor inválido");
    if (valor > saldo) throw ErroSaldo(valor - saldo);
    std::cout << "saque de " << valor << " autorizado\n";
}

int main() {
    try {
        sacar(100.0, 30.0);
        sacar(100.0, -5.0);
    } catch (const std::invalid_argument& e) {
        std::cout << "argumento: " << e.what() << "\n";
    }

    try {
        sacar(100.0, 250.0);
    } catch (const ErroSaldo& e) {
        std::cout << e.what() << " — faltam " << e.faltando() << "\n";
    } catch (const std::exception& e) {
        std::cout << "outro erro: " << e.what() << "\n";
    }
    return 0;
}
