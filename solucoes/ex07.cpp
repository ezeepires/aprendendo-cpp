// SOLUÇÃO 07 — Conta bancária
#include <iostream>

class Conta {
public:
    explicit Conta(double saldo_inicial) : saldo_(saldo_inicial) {}

    void depositar(double valor) {
        if (valor > 0) saldo_ += valor;
    }

    bool sacar(double valor) {
        if (valor <= 0 || valor > saldo_) return false;
        saldo_ -= valor;
        return true;
    }

    double saldo() const { return saldo_; }

private:
    double saldo_ = 0.0;
};

int main() {
    Conta conta(100.0);
    std::cout << "Saldo inicial: " << conta.saldo() << "\n";

    conta.depositar(50.0);
    std::cout << "Depois de depositar 50: " << conta.saldo() << "\n";

    std::cout << "Saque de 30: " << (conta.sacar(30.0) ? "ok" : "negado") << "\n";
    std::cout << "Saldo: " << conta.saldo() << "\n";

    std::cout << "Saque de 500: " << (conta.sacar(500.0) ? "ok" : "negado") << "\n";
    std::cout << "Saldo: " << conta.saldo() << "\n";
    return 0;
}
