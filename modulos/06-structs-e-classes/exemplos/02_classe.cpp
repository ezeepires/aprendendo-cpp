// Classe com encapsulamento e invariantes.
#include <iostream>
#include <stdexcept>
#include <string>

class ContaBancaria {
public:
    ContaBancaria(std::string titular, double saldo_inicial = 0.0)
        : titular_(std::move(titular)), saldo_(saldo_inicial) {
        if (saldo_inicial < 0.0) {
            throw std::invalid_argument("saldo inicial não pode ser negativo");
        }
    }

    const std::string& titular() const { return titular_; }
    double saldo() const { return saldo_; }

    void depositar(double valor) {
        if (valor <= 0.0) {
            std::cout << "  depósito ignorado: valor inválido\n";
            return;
        }
        saldo_ += valor;
    }

    bool sacar(double valor) {
        if (valor <= 0.0 || valor > saldo_) {
            return false;                 // nunca deixa o saldo negativo
        }
        saldo_ -= valor;
        return true;
    }

private:
    std::string titular_;
    double saldo_ = 0.0;
};

int main() {
    ContaBancaria conta("Ana", 100.0);

    conta.depositar(50.0);
    std::cout << conta.titular() << " tem " << conta.saldo() << "\n";

    std::cout << "sacar 30: " << (conta.sacar(30.0) ? "ok" : "falhou") << "\n";
    std::cout << "saldo: " << conta.saldo() << "\n";

    std::cout << "sacar 1000: " << (conta.sacar(1000.0) ? "ok" : "falhou") << "\n";
    std::cout << "saldo: " << conta.saldo() << "\n";

    conta.depositar(-5.0);   // ignorado pela classe

    try {
        ContaBancaria invalida("Bia", -10.0);
    } catch (const std::exception& e) {
        std::cout << "erro esperado: " << e.what() << "\n";
    }
    return 0;
}
