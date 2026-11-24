// Exercício 03 — Classe template Par<T>
//
// Complete a classe Par<T>:
//   maior() → devolve o maior dos dois valores
//   trocar() → inverte primeiro e segundo
//   soma() → devolve primeiro + segundo
#include <string>
#include "teste.hpp"

template <typename T>
class Par {
public:
    Par(T primeiro, T segundo) : primeiro_(primeiro), segundo_(segundo) {}

    T maior() const {
        // TODO
        return primeiro_;
    }

    T soma() const {
        // TODO
        return T{};
    }

    void trocar() {
        // TODO
    }

    const T& primeiro() const { return primeiro_; }
    const T& segundo() const { return segundo_; }

private:
    T primeiro_;
    T segundo_;
};

int main() {
    Par<int> a(3, 7);
    CHECK_IGUAL(7, a.maior());
    CHECK_IGUAL(10, a.soma());
    a.trocar();
    CHECK_IGUAL(7, a.primeiro());
    CHECK_IGUAL(3, a.segundo());
    CHECK_IGUAL(7, a.maior());

    Par<std::string> b("ana", "bia");
    CHECK_IGUAL(std::string("bia"), b.maior());
    CHECK_IGUAL(std::string("anabia"), b.soma());

    Par<double> c(1.5, 2.5);
    CHECK_PROXIMO(4.0, c.soma(), 0.0001);
    return teste::resumo("ex03 · Par<T>");
}
