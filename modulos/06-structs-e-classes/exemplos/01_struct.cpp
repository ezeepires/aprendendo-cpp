// Structs: agrupar dados e dar comportamento.
#include <cmath>
#include <iostream>
#include <string>

struct Ponto {
    double x = 0.0;
    double y = 0.0;

    double distancia_ate(const Ponto& outro) const {
        const double dx = x - outro.x;
        const double dy = y - outro.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    void mover(double dx, double dy) {
        x += dx;
        y += dy;
    }

    std::string texto() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

int main() {
    Ponto a{0.0, 0.0};
    Ponto b{3.0, 4.0};

    std::cout << "a = " << a.texto() << "\n";
    std::cout << "b = " << b.texto() << "\n";
    std::cout << "distância = " << a.distancia_ate(b) << "\n";

    a.mover(1.0, 1.0);
    std::cout << "a depois de mover = " << a.texto() << "\n";
    std::cout << "nova distância = " << a.distancia_ate(b) << "\n";
    return 0;
}
