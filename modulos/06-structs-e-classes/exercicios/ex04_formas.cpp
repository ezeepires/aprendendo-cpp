// Exercício 04 — Polimorfismo
//
// Complete area() e nome() em Circulo e Retangulo.
// Depois implemente total_area() somando as áreas de todas as formas.
// Note que o vetor guarda unique_ptr<Forma> — por isso o destrutor virtual
// da base é essencial.
#include <memory>
#include <numbers>
#include <string>
#include <vector>
#include "teste.hpp"

class Forma {
public:
    virtual ~Forma() = default;
    virtual double area() const = 0;
    virtual std::string nome() const = 0;
};

class Circulo : public Forma {
public:
    explicit Circulo(double raio) : raio_(raio) {}
    double area() const override {
        // TODO: π * r²
        return 0.0;
    }
    std::string nome() const override {
        // TODO: "círculo"
        return "";
    }
private:
    double raio_;
};

class Retangulo : public Forma {
public:
    Retangulo(double largura, double altura) : largura_(largura), altura_(altura) {}
    double area() const override {
        // TODO
        return 0.0;
    }
    std::string nome() const override {
        // TODO: "retângulo"
        return "";
    }
private:
    double largura_;
    double altura_;
};

double total_area(const std::vector<std::unique_ptr<Forma>>& formas) {
    // TODO
    return 0.0;
}

int main() {
    Circulo c(1.0);
    CHECK_PROXIMO(std::numbers::pi, c.area(), 0.0001);
    CHECK_IGUAL(std::string("círculo"), c.nome());

    Retangulo r(2.0, 3.0);
    CHECK_PROXIMO(6.0, r.area(), 0.0001);
    CHECK_IGUAL(std::string("retângulo"), r.nome());

    std::vector<std::unique_ptr<Forma>> formas;
    formas.push_back(std::make_unique<Circulo>(1.0));
    formas.push_back(std::make_unique<Retangulo>(2.0, 3.0));
    CHECK_PROXIMO(std::numbers::pi + 6.0, total_area(formas), 0.0001);

    std::vector<std::unique_ptr<Forma>> vazio;
    CHECK_PROXIMO(0.0, total_area(vazio), 0.0001);
    return teste::resumo("ex04 · formas");
}
