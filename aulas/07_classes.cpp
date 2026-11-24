// AULA 07 — Criando seus próprios tipos: struct e class
//
// Compile: g++ -std=c++20 -Wall -Wextra aulas/07_classes.cpp -o programa
// Rode:    ./programa

#include <iostream>
#include <string>

// struct: um pacote de dados (tudo público)
struct Ponto {
    double x = 0.0;
    double y = 0.0;

    void mover(double dx, double dy) {
        x += dx;
        y += dy;
    }

    void mostrar() const {          // const = não altera o objeto
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

// class: parecido, mas com partes privadas e construtor
class Conta {
public:
    // Construtor: roda quando o objeto é criado
    Conta(std::string dono, double saldo_inicial)
        : dono_(dono), saldo_(saldo_inicial) {}

    void depositar(double valor) {
        if (valor > 0) saldo_ += valor;
    }

    bool sacar(double valor) {
        if (valor <= 0 || valor > saldo_) return false;
        saldo_ -= valor;
        return true;
    }

    double saldo() const { return saldo_; }
    const std::string& dono() const { return dono_; }

private:
    // Só os métodos da própria classe podem mexer aqui
    std::string dono_;
    double saldo_ = 0.0;
};

int main() {
    Ponto p{1.0, 2.0};
    std::cout << "ponto: ";
    p.mostrar();

    p.mover(3.0, 4.0);
    std::cout << "depois de mover: ";
    p.mostrar();

    Conta conta("Ana", 100.0);
    conta.depositar(50.0);
    std::cout << "\n" << conta.dono() << " tem " << conta.saldo() << "\n";

    if (conta.sacar(30.0)) {
        std::cout << "sacou 30 -> saldo " << conta.saldo() << "\n";
    }

    if (!conta.sacar(1000.0)) {
        std::cout << "não deu para sacar 1000 (saldo insuficiente)\n";
    }

    return 0;
}
