// Exercício 01 — Struct Ponto
//
// Complete os métodos:
//   distancia_ate(outro) → distância euclidiana: sqrt(dx² + dy²)
//   mover(dx, dy)        → soma dx em x e dy em y
// Dica: #include <cmath> e std::sqrt.
#include <cmath>
#include "teste.hpp"

struct Ponto {
    double x = 0.0;
    double y = 0.0;

    double distancia_ate(const Ponto& outro) const {
        // TODO
        return 0.0;
    }

    void mover(double dx, double dy) {
        // TODO
    }
};

int main() {
    Ponto a{0.0, 0.0};
    Ponto b{3.0, 4.0};

    CHECK_PROXIMO(5.0, a.distancia_ate(b), 0.0001);
    CHECK_PROXIMO(5.0, b.distancia_ate(a), 0.0001);
    CHECK_PROXIMO(0.0, a.distancia_ate(a), 0.0001);

    a.mover(1.0, 2.0);
    CHECK_PROXIMO(1.0, a.x, 0.0001);
    CHECK_PROXIMO(2.0, a.y, 0.0001);

    b.mover(-3.0, -4.0);
    CHECK_PROXIMO(0.0, b.x, 0.0001);
    CHECK_PROXIMO(0.0, b.y, 0.0001);
    return teste::resumo("ex01 · ponto");
}
