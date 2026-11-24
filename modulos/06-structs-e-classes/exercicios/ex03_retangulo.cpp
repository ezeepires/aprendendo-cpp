// Exercício 03 — Retângulo com métodos const
//
// Implemente area(), perimetro() e escalar(fator).
// Os dois primeiros devem ser const (não alteram o objeto).
// escalar multiplica largura e altura pelo fator.
#include "teste.hpp"

class Retangulo {
public:
    Retangulo(double largura, double altura) : largura_(largura), altura_(altura) {}

    double area() const {
        // TODO
        return 0.0;
    }

    double perimetro() const {
        // TODO
        return 0.0;
    }

    void escalar(double fator) {
        // TODO
    }

    double largura() const { return largura_; }
    double altura() const { return altura_; }

private:
    double largura_ = 0.0;
    double altura_ = 0.0;
};

int main() {
    const Retangulo r(3.0, 4.0);       // const: só métodos const funcionam
    CHECK_PROXIMO(12.0, r.area(), 0.0001);
    CHECK_PROXIMO(14.0, r.perimetro(), 0.0001);

    Retangulo quadrado(2.0, 2.0);
    quadrado.escalar(3.0);
    CHECK_PROXIMO(6.0, quadrado.largura(), 0.0001);
    CHECK_PROXIMO(6.0, quadrado.altura(), 0.0001);
    CHECK_PROXIMO(36.0, quadrado.area(), 0.0001);

    quadrado.escalar(0.5);
    CHECK_PROXIMO(9.0, quadrado.area(), 0.0001);
    return teste::resumo("ex03 · retângulo");
}
