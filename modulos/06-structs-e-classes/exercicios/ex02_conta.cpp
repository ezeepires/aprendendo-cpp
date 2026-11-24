// Exercício 02 — Conta bancária
//
// Complete os métodos da classe:
//   depositar(valor): soma ao saldo se valor > 0, senão ignora
//   sacar(valor): devolve true e subtrai se 0 < valor <= saldo; senão false
//   saldo(): já está pronto
// Regra de ouro: o saldo NUNCA pode ficar negativo.
#include <string>
#include "teste.hpp"

class Conta {
public:
    explicit Conta(double saldo_inicial = 0.0) : saldo_(saldo_inicial) {}

    void depositar(double valor) {
        // TODO
    }

    bool sacar(double valor) {
        // TODO
        return false;
    }

    double saldo() const { return saldo_; }

private:
    double saldo_ = 0.0;
};

int main() {
    Conta c(100.0);
    CHECK_PROXIMO(100.0, c.saldo(), 0.0001);

    c.depositar(50.0);
    CHECK_PROXIMO(150.0, c.saldo(), 0.0001);

    c.depositar(-10.0);          // ignorado
    c.depositar(0.0);            // ignorado
    CHECK_PROXIMO(150.0, c.saldo(), 0.0001);

    CHECK(c.sacar(50.0));
    CHECK_PROXIMO(100.0, c.saldo(), 0.0001);

    CHECK(!c.sacar(500.0));      // saldo insuficiente
    CHECK_PROXIMO(100.0, c.saldo(), 0.0001);

    CHECK(!c.sacar(-1.0));       // valor inválido
    CHECK(c.sacar(100.0));       // zerar é permitido
    CHECK_PROXIMO(0.0, c.saldo(), 0.0001);
    return teste::resumo("ex02 · conta");
}
